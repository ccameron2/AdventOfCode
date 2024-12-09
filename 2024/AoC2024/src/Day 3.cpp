#include "Day.h"

#include <iostream>
#include <ranges>
#include <string>


bool Day3::Init()
{
    std::fstream inFile("../../../AoC2024/input/input3.txt");
    char ch;
    if(inFile)
    {
        while(inFile >> ch) InString.push_back(ch);
        return true;
    }
    return false;
}

void Day3::Run()
{
    std::vector<char> safeChars{'m','u','l','(',',',')'};
    std::vector<std::string> output;
    std::vector<std::pair<int,int>> elements;
    int safeIndex;
    int checkIndex;
    for(int i = 0; i < InString.size(); i+= checkIndex)
    {
        checkIndex = 0;
        safeIndex = 0;
        if(i + checkIndex > InString.size() - 1) break;
        std::string element1;
        std::string element2;
       
        bool failed = false;
        while (!failed)
        {
            char ch = InString[i + checkIndex];
            if(safeIndex == safeChars.size())
            {
                elements.push_back(std::make_pair<int,int>(stoi(element1),stoi(element2)));
                break;
            }
            if(ch == safeChars[safeIndex])
            {
                if(safeIndex == 3)
                {
                    int digitIndex = 1;
                    
                    while(isdigit(InString[i + checkIndex + digitIndex]))
                    {
                        element1.push_back(InString[i + checkIndex + digitIndex]);
                        digitIndex++;
                    }
                    
                    checkIndex += digitIndex;
                    safeIndex++;
                    continue;
                }
                if(safeIndex == 4)
                {
                    int digitIndex = 1;
                    while(isdigit(InString[i + checkIndex + digitIndex]))
                    {
                        element2.push_back(InString[i + checkIndex + digitIndex]);
                        digitIndex++;
                    }
                    checkIndex += digitIndex;
                    safeIndex++;
                    continue;
                }
                safeIndex++;
                checkIndex++;
            }
            else
            {
                failed = true;
                checkIndex++;
            }
        }
    }

    int finalCount = 0;
    for(auto& element : elements)
    {
        finalCount += element.first * element.second;
    }
    std::cout << finalCount << std::endl;
}
