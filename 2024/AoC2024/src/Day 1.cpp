#include "Day.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


bool Day1::Init()
{
    std::ifstream inFile("../../../AoC2024/input/input1.txt");
    if(inFile.is_open())
    {
        std::string inString;
        while(inFile >> inString)
        {
            List1.push_back(std::stoi(inString));
            inFile >> inString;
            List2.push_back(std::stoi(inString));
        }
        return true;
    }
    return false;
}

void Day1::Run()
{
    std::sort(List1.begin(), List1.end());
    std::sort(List2.begin(), List2.end());

    int result = 0;
    for(int i = 0; i < List1.size(); i++)
    {
        int a = std::max(List1[i], List2[i]);
        int b = std::min(List1[i], List2[i]);
        result += a - b;
    }

    std::cout << "Part 1 Result: " << result << std::endl;
    result = 0;
    
    for(int& num1 : List1)
    {
        int timesFound = 0;
        for(const int& num2 : List2)
        {
            if(num1 == num2) timesFound++;
        }
        num1 *= timesFound;
        result += num1;
    }
    std::cout << "Part 2 Result: " << result << std::endl;
}

