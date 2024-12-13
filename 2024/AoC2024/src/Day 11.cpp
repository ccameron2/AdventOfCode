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
    int blinkCount = 8;
    for(int i = 0; i < blinkCount; i++)
    {
        Blink();
    }
    std::cout << Stones.size() << std::endl;
}

void Day11::Blink()
{
    std::vector<Stone> newStones;
    for(Stone& stone : Stones)
    {
        if(std::stoul(stone.Engraving) < 0)
        {
            std::cout << "Negative engraving!" << std::endl;
        }
        std::cout << stone.Engraving << " ";
        
        if(stone.Engraving == "0")
        {
            stone.Engraving = "1";
            newStones.push_back(stone);
            continue;
        }
        if(stone.Engraving.size() % 2 == 0)
        {
            Stone newStone = Split(stone);
            newStones.push_back(stone);
            newStones.push_back(newStone);
            continue;
        }
        stone.Engraving = std::to_string(std::stoul(stone.Engraving) * 2024);
        newStones.push_back(stone);
    }
    std::cout << std::endl;
    Stones = newStones;
}

Day11::Stone Day11::Split(Stone& source)
{
    Stone newStone;
    for(int i = source.Engraving.length() / 2; i < source.Engraving.length(); i++)
    {
        newStone.Engraving.push_back(source.Engraving[i]);
    }
    source.Engraving.erase(source.Engraving.length() / 2);

    // correct 0s
    if(!std::stoul(source.Engraving))
    {
        source.Engraving = "0";
    }
    if(!std::stoul(newStone.Engraving))
    {
        newStone.Engraving = "0";
    }
    if(source.Engraving.size() > 1)
    {
        int index = 0;
        bool found = false;
        while(source.Engraving[index] == '0')
        {
            found = true;
            index++;
        }
            
        if(found)
        {
            source.Engraving.erase(0,index);
        }
    }
    if(newStone.Engraving.size() > 1)
    {
        int index = 0;
        bool found = false;
        while(newStone.Engraving[index] == '0')
        {
            found = true;
            index++;
        }
            
        if(found)
        {
            newStone.Engraving.erase(0,index);
        }
    }
    return newStone;
}