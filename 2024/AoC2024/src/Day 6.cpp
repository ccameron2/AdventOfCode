#include "Day.h"

bool Day6::Init()
{

    std::fstream inFile("../../../AoC2024/input/input6test.txt");
    if(inFile)
    {
        std::string inString;
        int index = 0;
        while(inFile >> inString)
        {
            Room.push_back(std::vector<char>());
            for(auto& inChar : inString)
            {
                Room[index].push_back(inChar);
            }
            index++;
        }
        return true;
    }
    return false;
}

void Day6::Run()
{
    for(int i = 0; i < Room.size(); i++)
    {
        for(int j = 0; j < Room[i].size(); j++)
        {
            char ch = Room[i][j];
            if(ch == '^')
            {
                MoveNorth(i,j);
            }
            if(ch == '^')
            {
                MoveEast(i,j);
            }
            if(ch == '^')
            {
                MoveSouth(i,j);
            }
            if(ch == '^')
            {
                MoveWest(i,j);
            }
        }
        std::cout << std::endl;
    }
}

bool Day6::MoveNorth(int i, int j)
{
    if(Room[i + 1][j] == '#')
        return false;

    int index = 1;
    while(Room[i + index][j] != '#' && i + index < Room.size())
    {
        
    }
}
