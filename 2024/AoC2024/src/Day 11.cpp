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
    NumWorkers = std::thread::hardware_concurrency();
    if (NumWorkers == 0)  NumWorkers = 8;
    --NumWorkers;

    for (uint32_t i = 0; i < NumWorkers; ++i)
    {
        BlinkWorkers[i].first.Thread = std::thread(&Day11::BlinkThread, this, i);
    }
    
    int blinkCount = 25;
    for(int i = 0; i < blinkCount; i++)
    {
        std::vector<std::vector<Stone>> newStoneLists;
        newStoneLists.resize(NumWorkers + 1);
        std::vector<std::vector<uint32_t>> newStoneIndicesLists;
        newStoneIndicesLists.resize(NumWorkers + 1);

        int chunkSize = (Stones.size() / 2) / (NumWorkers + 1);
        std::vector<Stone> newStones;
        std::vector<uint32_t> newStoneIndices;
        Stone* stones = &Stones[0];
        for(uint32_t i = 0; i < NumWorkers; i++)
        {
            BlinkWork& work = BlinkWorkers[i].second;
            work.Stones = stones;
            work.NumStones = chunkSize;
            work.NewStones.clear();
            work.NewStoneIndices.clear();
            
            auto& workerThread = BlinkWorkers[i].first;
            {
                std::unique_lock<std::mutex> l(workerThread.Lock);
                work.Complete = false;
            }

            workerThread.WorkReady.notify_one();

            stones += work.NumStones;
        }
        uint32_t numRemainingStones = (Stones.size() / 2) - static_cast<uint64_t>(stones - &Stones[0]);
        CheckStones(stones,numRemainingStones,newStones, newStoneIndices);

        for (uint32_t i = 0; i < NumWorkers; ++i)
        {
            auto& workerThread = BlinkWorkers[i].first;
            auto& work = BlinkWorkers[i].second;
                
            std::unique_lock<std::mutex> l(workerThread.Lock);
            workerThread.WorkReady.wait(l, [&]() { return work.Complete; });

            newStoneLists[i] = newStones;
            newStoneIndicesLists[i] = newStoneIndices;
        }
        
        // do this on the thread not here
        // collect stones from threads into list
        std::vector<Stone> finalStones;

        for(int i = 0; i < NumWorkers; i++)
        {
            int index = 0;
            for(int j = 0; j < chunkSize; j++) // need to use length of a chunk of stones
            {
                if(j == newStoneIndicesLists[i][index])
                {
                    finalStones.push_back(newStones[i]);
                    index++;
                }
            }
            finalStones.push_back();
        }
    }
    std::cout << Stones.size() << std::endl;
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

        CheckStones(work.Stones, work.NumStones, work.NewStones, work.NewStoneIndices);
			
        {
            std::unique_lock<std::mutex> l(worker.Lock);
            work.Complete = true;
        }

        worker.WorkReady.notify_one();
    }
}

void Day11::CheckStones(Stone* stones, uint64_t numStones, std::vector<Stone>& newStones, std::vector<uint32_t>& newStoneIndices)
{
    int index = 0;
    Stone* endStone = stones + numStones - 1;
    do
    {
        if(stones->Engraving == 0)
        {
            stones->Engraving = 1;
            stones++;
            index++;
            continue;
        }
        if(std::to_string(stones->Engraving).size() % 2 == 0)
        {
            Stone newStone = Split(*stones);
            newStones.push_back(newStone);
            newStoneIndices.push_back(++index);
            index++;
            stones++;
            continue;
        }
        stones->Engraving *= 2024;
        stones++;
        index++;
    }
    while(stones != endStone);
}

