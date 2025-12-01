#include "Day1/Day1.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Day1::Day1()
{
    std::vector<std::string> InputStrings;
    
    std::ifstream file(InputFile);

    if (file.is_open()) 
    {
        std::string line;
        while (std::getline(file, line)) 
        {
            InputStrings.push_back(line);
        }
    }
    file.close();
    
    Safe safe;
    for (auto& str : InputStrings)
    {
        std::string numComp;
        for (std::string::iterator it = str.begin() + 1; it != str.end(); ++it)
        {
            char c = *it;
            numComp += c;
        }
        int readNumber = std::stoi(numComp);
        str[0] == 'R' ? safe.NextCombination(0, readNumber) : safe.NextCombination(1, readNumber);
    }
    safe.PrintResult();
}

void Safe::NextCombination(int dir, int movement)
{
    int numCycles = movement / 100;
    if (numCycles > 0)
    {
        movement -= numCycles * 100;
        
    }
    NumTimesZero += numCycles;
    
    if (dir == 0)
    {
        bool wasAlreadyZero = CurrentPosition == 0;
        CurrentPosition += movement;
        if (CurrentPosition >= TopValue)
        {
            int remainder = CurrentPosition - TopValue;
            CurrentPosition = remainder;
            if (CurrentPosition != 0)
            {
                if (!wasAlreadyZero)
                {
                    NumTimesZero++;
                }
            }
        }
    }
    else
    {
        bool wasAlreadyZero = CurrentPosition == 0;
        CurrentPosition -= movement;
        if (CurrentPosition < 0)
        {
            CurrentPosition += TopValue;
            if (CurrentPosition != 0)
            {
                if (!wasAlreadyZero)
                {
                    NumTimesZero++;
                }
            }
        }
    }
    
    if (CurrentPosition == 0) 
        NumTimesZero++;
}

void Safe::PrintResult()
{
    std::cout << "Result: " << NumTimesZero << std::endl;
}
