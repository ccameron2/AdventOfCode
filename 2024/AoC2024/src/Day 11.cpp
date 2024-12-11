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
    int blinkCount = 25;
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
        if(std::stoi(stone.Engraving) < 0)
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
        stone.Engraving = std::to_string(std::stoi(stone.Engraving) * 2024);
        newStones.push_back(stone);
    }
    //std::cout << std::endl;
    Stones = newStones;
}

