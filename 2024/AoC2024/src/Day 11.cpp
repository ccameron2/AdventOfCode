#include "Day.h"

bool Day11::Init()
{
    std::fstream inFile("../../../AoC2024/input/input11.txt");
    std::string line;
    
   if(inFile.is_open())
   {
       while(inFile >> line)
       {
           Stone newStone(line);
           Stones.push_back(newStone);
       }
       return true;
   }
    return false;
}

void Day11::Run()
{
    //NumWorkers = std::thread::hardware_concurrency();
    NumWorkers = Stones.size();
    NumWorkers--; // main thread
    
    for (uint32_t i = 0; i < NumWorkers; ++i)
    {
        BlinkWorkers[i].first.Thread = std::thread(&Day11::BlinkThread, this, i);
    }
    
    std::vector<std::vector<Stone>> stoneLists;
    for(Stone stone : Stones)
    {
        std::vector<Stone> stones;
        stones.push_back(stone);
        stoneLists.push_back(stones);
    }
    
    int blinkCount = 50;
    for(int b = 0; b < blinkCount; b++)
    {
        for(uint32_t i = 0; i < NumWorkers; i++)
        {
            BlinkWork& work = BlinkWorkers[i].second;
            work.InStones = stoneLists[i];
            work.NumStones = stoneLists[i].size();
            work.NewStones.clear();
            
            auto& workerThread = BlinkWorkers[i].first;
            {
                std::unique_lock<std::mutex> l(workerThread.Lock);
                work.Complete = false;
            }

            workerThread.WorkReady.notify_one();
        }

        std::vector<Stone> mainThreadStones;
        CheckStones(stoneLists[stoneLists.size() - 1], mainThreadStones);
        
        std::vector<std::vector<Stone>> newStoneLists;
        for (uint32_t i = 0; i < NumWorkers; ++i)
        {
            auto& workerThread = BlinkWorkers[i].first;
            auto& work = BlinkWorkers[i].second;
                
            std::unique_lock<std::mutex> l(workerThread.Lock);
            workerThread.WorkReady.wait(l, [&]() { return work.Complete; });

            newStoneLists.push_back(BlinkWorkers[i].second.NewStones);
        }
        newStoneLists.push_back(mainThreadStones);

        stoneLists.clear();
        stoneLists = newStoneLists;
    }
    
    uint64_t stoneCount = 0;
    for(auto stoneList : stoneLists)
    {
        stoneCount += stoneList.size();
    }
    std::cout << stoneCount << std::endl;
}

void Day11::Blink()
{
    std::vector<Stone> newStones;
    for(Stone& stone : Stones)
    {
        if(stone.Engraving == 0)
        {
            stone.Engraving = 1;
            newStones.push_back(stone);
            continue;
        }
        if(std::to_string(stone.Engraving).size() % 2 == 0)
        {
            Stone newStone = Split(stone);
            newStones.push_back(stone);
            newStones.push_back(newStone);
            continue;
        }
        stone.Engraving *= 2024;
        newStones.push_back(stone);
    }

    Stones = newStones;
}

Day11::Stone Day11::Split(Stone& source)
{
    Stone newStone;
    std::string newStoneEngraving;
    std::string sourceStoneEngraving = std::to_string(source.Engraving);
    for(int i = sourceStoneEngraving.size() / 2; i < sourceStoneEngraving.size(); i++)
    {
        newStoneEngraving.push_back(sourceStoneEngraving[i]);
    }
    sourceStoneEngraving.erase(sourceStoneEngraving.size() / 2, sourceStoneEngraving.size() / 2);

    source.Engraving = std::stoul(sourceStoneEngraving);
    newStone.Engraving = std::stoul(newStoneEngraving);
    
    return newStone;
}

void Day11::BlinkThread(uint32_t thread)
{
    WorkerThread& worker = BlinkWorkers[thread].first;
    BlinkWork& work = BlinkWorkers[thread].second;

    while (true)
    {
        {
            std::unique_lock<std::mutex> l(worker.Lock);
            worker.WorkReady.wait(l, [&]() { return !work.Complete; });
        }

        CheckStones(work.InStones, work.NewStones);
			
        {
            std::unique_lock<std::mutex> l(worker.Lock);
            work.Complete = true;
        }

        worker.WorkReady.notify_one();
    }
}

void Day11::CheckStones(std::vector<Stone>& stones, std::vector<Stone>& newStones)
{
    for(auto& stone : stones)
    {
        if(stone.Engraving == 0)
        {
            stone.Engraving = 1;
            newStones.push_back(stone);
            continue;
        }
        if(std::to_string(stone.Engraving).size() % 2 == 0)
        {
            Stone newStone = Split(stone);
            newStones.push_back(stone);
            newStones.push_back(newStone);
            continue;
        }
        stone.Engraving *= 2024;
        newStones.push_back(stone);
    }
}

