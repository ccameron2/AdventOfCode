#include <iostream>

#include "Day.h"

bool Day4::Init()
{
    std::fstream inFile("../../../AoC2024/input/input4.txt");
    if(inFile)
    {
        std::string inStr;
        while(inFile >> inStr)
        {
            std::vector<char> line;
            for(char &c : inStr)
            {
                line.push_back(c);
            }
            WordSearch.push_back(line);
        }
        return true;
    }
    return false;
}

void Day4::Run()
{
    int count = 0;
    for(int y = 0; y < WordSearch.size(); y++)
    {
        for(int x = 0; x < WordSearch[y].size(); x++)
        {
            Coord coord{x,y};
            for(int i = 0; i < 8; i++)
            {
                if(CheckDirection(static_cast<Direction>(i),coord)) count++;
            }
        }
    }
    std::cout << count << std::endl;
}

bool Day4::CheckNorth(Coord coord) const
{
    if(coord.y - 3 > WordSearch.size() - 1) return false;
    
    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y - 1][coord.x] != 'M') return false;
    if(WordSearch[coord.y - 2][coord.x] != 'A') return false;
    if(WordSearch[coord.y - 3][coord.x] != 'S') return false;
    
    return true;
}

bool Day4::CheckEast(Coord coord) const
{
    if(coord.x + 3 > WordSearch[0].size() - 1) return false;

    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y][coord.x + 1] != 'M') return false;
    if(WordSearch[coord.y][coord.x + 2] != 'A') return false;
    if(WordSearch[coord.y][coord.x + 3] != 'S') return false;
     
    return true;
}

bool Day4::CheckSouth(Coord coord) const
{
    if(coord.y + 3 > WordSearch.size() - 1) return false;
    
    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y + 1][coord.x] != 'M') return false;
    if(WordSearch[coord.y + 2][coord.x] != 'A') return false;
    if(WordSearch[coord.y + 3][coord.x] != 'S') return false;

    return true;
}

bool Day4::CheckWest(Coord coord) const
{
    if(coord.x - 3 < 0) return false;
    
    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y][coord.x - 1] != 'M') return false;
    if(WordSearch[coord.y][coord.x - 2] != 'A') return false;
    if(WordSearch[coord.y][coord.x - 3] != 'S') return false;

    return true;
}

bool Day4::CheckNorthEast(Coord coord) const
{
    if(coord.y + 3 > WordSearch.size() - 1 || coord.x + 3 > WordSearch[0].size() - 1) return false;
    
    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y + 1][coord.x + 1] != 'M') return false;
    if(WordSearch[coord.y + 2][coord.x + 2] != 'A') return false;
    if(WordSearch[coord.y + 3][coord.x + 3] != 'S') return false;

    return true;
}

bool Day4::CheckSouthEast(Coord coord) const
{
    if(coord.y - 3 < 0 || coord.x + 3 > WordSearch[0].size() - 1) return false;

    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y - 1][coord.x + 1] != 'M') return false;
    if(WordSearch[coord.y - 2][coord.x + 2] != 'A') return false;
    if(WordSearch[coord.y - 3][coord.x + 3] != 'S') return false;
}

bool Day4::CheckSouthWest(Coord coord) const
{
    if(coord.y - 3 < 0 || coord.x - 3 < 0) return false;

    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y - 1][coord.x - 1] != 'M') return false;
    if(WordSearch[coord.y - 2][coord.x - 2] != 'A') return false;
    if(WordSearch[coord.y - 3][coord.x - 3] != 'S') return false;
}

bool Day4::CheckNorthWest(Coord coord) const
{
    if(coord.y + 3 > WordSearch.size() - 1 || coord.x - 3 < 0 ) return false;

    if(WordSearch[coord.y][coord.x] != 'X') return false;
    if(WordSearch[coord.y + 1][coord.x - 1] != 'M') return false;
    if(WordSearch[coord.y + 2][coord.x - 2] != 'A') return false;
    if(WordSearch[coord.y + 3][coord.x - 3] != 'S') return false;
}

bool Day4::CheckDirection(Direction direction, Coord coord) const
{
    std::string buildString;
    bool found = false;
    switch(direction)
    {
    case North:
        found = CheckNorth(coord);
        break;
    case NorthEast:
        found = CheckNorthEast(coord);
        break;
    case East:
        found = CheckEast(coord);
        break;
    case SouthEast:
        found = CheckSouthEast(coord);
        break;
    case South:
        found = CheckSouth(coord);
        break;
    case SouthWest:
        found = CheckSouthWest(coord);
        break;
    case West:
        found = CheckWest(coord);
        break;
    case NorthWest:
        found = CheckNorthWest(coord);
        break;
    }
    return found;
}
