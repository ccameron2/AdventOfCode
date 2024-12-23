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
        //std::cout << stone.Engraving << " ";
        
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
    //std::cout << std::endl;
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


//
// int Day11::ScanZeros(Stone input)
// {
//     int index = 0;
//     bool found = false;
//     while(input.Engraving[index] == '0')
//     {
//         found = true;
//         index++;
//     }
//     if(found)
//     {
//         return index;
//     }
//     return 0;
// }
