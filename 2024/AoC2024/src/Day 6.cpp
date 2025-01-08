#include "Day.h"

bool Day6::Init()
{

    std::fstream inFile("../../../AoC2024/input/input6test.txt");
    if(inFile)
    {
        std::string inString;
        int index = 0;
        int xIndex = 0;
        while(inFile >> inString)
        {
            Room.push_back(std::vector<char>());
            for(auto& inChar : inString)
            {
                Room[index].push_back(inChar);
                xIndex++;
                if(inChar == '^')
                {
                    CurrentCoord = {xIndex,index};
                    CurrentDirection = Direction::North; 
                }
            }
            index++;
        }
        return true;
    }
    return false;
}

void Day6::Run()
{
    while(CurrentCoord.x < Room[CurrentCoord.y].size() && CurrentCoord.y < Room.size() && CurrentCoord.y > 0 && CurrentCoord.x > 0)
    {
        std::pair<Coord,bool> result;
        if(CurrentDirection == Direction::North)
        {
            result = MoveNorth(CurrentCoord);
            
            if(!result.second) break;
            CurrentDirection = Direction::East;
        }
        else if(CurrentDirection == Direction::East)
        {
            result = MoveEast(CurrentCoord);
            
            if(!result.second) break;
            CurrentDirection = Direction::South;
        }
        else if(CurrentDirection == Direction::South)
        {
            result = MoveSouth(CurrentCoord);
            
            if(!result.second) break;
            CurrentDirection = Direction::West;
        }
        else // West
        {
            result = MoveWest(CurrentCoord);
            
            if(!result.second) break;
            CurrentDirection = Direction::North;
        }
        CurrentCoord = result.first;
    }
}

std::pair<Day6::Coord,bool> Day6::MoveNorth(Coord coord)
{
    if(Room[coord.y + 1][coord.x] == '#')
        return std::make_pair(coord, true);

    int index = 1;
    while(coord.y + index < Room.size())
    {
        char& checkChar = Room[coord.y + index][coord.x];
        if(checkChar == '#') return std::make_pair(Coord{coord.y + index - 1,coord.x}, true);
        if(checkChar != 'x')
        {
            checkChar = 'x';
            tileCount++;
        }
        index++;
    }
    return std::make_pair(coord, false);
}

std::pair<Day6::Coord,bool> Day6::MoveSouth(Coord coord)
{
    if(Room[coord.y - 1][coord.x] == '#')
        return std::make_pair(coord, true);

    int index = 1;
    while(coord.y - index > 0)
    {
        char& checkChar = Room[coord.y - index][coord.x];
        if(checkChar == '#') return std::make_pair(Coord{coord.y - index + 1,coord.x}, true);
        if(checkChar != 'x')
        {
            checkChar = 'x';
            tileCount++;
        }
        index++;
    }
    return std::make_pair(coord, false);
}