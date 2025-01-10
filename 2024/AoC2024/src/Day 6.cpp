#include "Day.h"

bool Day6::Init()
{
    std::fstream inFile("../../../AoC2024/input/input6.txt");
    if(inFile)
    {
        std::string inString;
        int index = 0;
        while(inFile >> inString)
        {
            int xIndex = 0;
            Room.push_back(std::vector<char>());
            for(auto& inChar : inString)
            {
                Room[index].push_back(inChar);
                if(inChar == '^')
                {
                    CurrentCoord = {xIndex,index};
                    CurrentDirection = Direction::North;
                    Room[index][xIndex] = 'x';
                    tileCount++;
                }
                xIndex++;
            }
            index++;
        }
        return true;
    }
    return false;
}

void Day6::Run()
{
    while(CurrentCoord.x < Room[CurrentCoord.y].size() && CurrentCoord.y < Room.size() && CurrentCoord.y >= 0 && CurrentCoord.x >= 0)
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
            
            if(!result.second)
                break;
            CurrentDirection = Direction::North;
        }
        CurrentCoord = result.first;
    }
    
    std::cout << std::endl;
    for(auto row : Room)
    {
        for(char ch : row)
        {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    
    std::cout << tileCount << std::endl;
}

std::pair<Day6::Coord,bool> Day6::MoveNorth(Coord coord)
{
    char res = Room[coord.y - 1][coord.x];
    if(res == '#')
        return std::make_pair(coord, true);

    int index = 1;
    while(coord.y - index >= 0)
    {
        char& checkChar = Room[coord.y - index][coord.x];
        if(checkChar == '#') return std::make_pair(Coord{coord.x,coord.y - index + 1}, true);
        if(checkChar != 'x')
        {
            checkChar = 'x';
            tileCount++;
        }
        index++;
    }
    return std::make_pair(coord, false);
}

std::pair<Day6::Coord,bool> Day6::MoveEast(Coord coord)
{
    if(Room[coord.y][coord.x + 1] == '#')
        return std::make_pair(coord, true);

    int index = 1;
    while(coord.x + index < Room[coord.y].size())
    {
        char& checkChar = Room[coord.y][coord.x + index];
        if(checkChar == '#') return std::make_pair(Coord{coord.x + index - 1, coord.y}, true);
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
    if(Room[coord.y + 1][coord.x] == '#')
        return std::make_pair(coord, true);

    int index = 1;
    while(coord.y + index < Room.size())
    {
        char& checkChar = Room[coord.y + index][coord.x];
        if(checkChar == '#') return std::make_pair(Coord{coord.x,coord.y + index - 1}, true);
        if(checkChar != 'x')
        {
            checkChar = 'x';
            tileCount++;
        }
        index++;
    }
    return std::make_pair(coord, false);
}

std::pair<Day6::Coord,bool> Day6::MoveWest(Coord coord)
{
    if(Room[coord.y][coord.x - 1] == '#')
        return std::make_pair(coord, true);

    int index = 1;
    while(coord.x - index >= 0)
    {

        char& checkChar = Room[coord.y][coord.x - index];
        if(checkChar == '#') return std::make_pair(Coord{coord.x - index + 1, coord.y}, true);
        if(checkChar != 'x')
        {
            checkChar = 'x';
            tileCount++;
        }
        index++;
    }
    return std::make_pair(coord, false);
}