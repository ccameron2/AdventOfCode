#include <algorithm>

#include "Day.h"

#include <ranges>

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
    std::vector<std::pair<int,int>> elements;
    
    int checkIndex;
    for(int i = 0; i < InString.size(); i+= checkIndex)
    {
        checkIndex = 1;
        if(InString[i] != 'm') continue;
        checkIndex++;
        if(InString[i + 1] != 'u') continue;
        checkIndex++;
        if(InString[i + 2] != 'l') continue;
        checkIndex++;
        if(InString[i + 3] != '(') continue;
        checkIndex++;
        
        if(!stoi(std::string{InString[i + 4]})) continue;
        
        int numIndex1 = 0;
        std::string inNum1;
        std::string charStr{InString[i + 4 + numIndex1]};
        while(std::any_of(charStr.begin(), charStr.end(), ::isdigit))
        {
            inNum1.push_back(InString[i + 4 + numIndex1]);
            numIndex1++;
            charStr = std::string{InString[i + 4 + numIndex1]};
        }
        checkIndex += numIndex1; // check
        
        if(InString[i + numIndex1 + 4] != ',') continue;
        checkIndex;
        
        if(!stoi(std::string{InString[i + numIndex1 + 5]})) continue;

        int numIndex2 = 0;
        std::string inNum2;
        std::string charStr2{InString[i + numIndex1 + 5 + numIndex2]};
        while(std::any_of(charStr2.begin(), charStr2.end(), ::isdigit))
        {
            inNum2.push_back(InString[i + numIndex1 + 5 + numIndex2]);
            numIndex2++;
            charStr2 = std::string{InString[i + numIndex1 + 5 + numIndex2]};
        }
        checkIndex += numIndex2;
        
        if(InString[i + numIndex1 + 5 + numIndex2] != ')') continue;

        elements.emplace_back(std::stoi(inNum1), std::stoi(inNum2));
    }

    int finalCount = 0;
    for(auto& element : elements)
    {
        finalCount += element.first * element.second;
    }
    std::cout << finalCount << std::endl;
}
