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
    
    int checkIndex = 0;
    for(int i = 0; i < InString.size(); i+= checkIndex)
    {
        checkIndex = 0;
        if(InString[i] == 'm')
        {
            checkIndex = CheckMul(i);
        }
        else
        {
            checkIndex++;
        }
    }

    int finalCount = 0;
    for(auto& element : Elements)
    {
        finalCount += element.first * element.second;
    }
    std::cout << finalCount << std::endl;
}

int Day3::CheckMul(int currentIndex)
{
    int checkIndex = 1;
    if(InString[currentIndex] != 'm') return checkIndex;
    checkIndex++;
    if(InString[currentIndex + 1] != 'u') return checkIndex;
    checkIndex++;
    if(InString[currentIndex + 2] != 'l') return checkIndex;
    checkIndex++;
    if(InString[currentIndex + 3] != '(') return checkIndex;
    checkIndex++;
        
    if(!stoi(std::string{InString[currentIndex + 4]})) return checkIndex;
        
    int numIndex1 = 0;
    std::string inNum1;
    std::string charStr{InString[currentIndex + 4 + numIndex1]};
    while(std::any_of(charStr.begin(), charStr.end(), ::isdigit))
    {
        inNum1.push_back(InString[currentIndex + 4 + numIndex1]);
        numIndex1++;
        charStr = std::string{InString[currentIndex + 4 + numIndex1]};
    }
    checkIndex += numIndex1; // check
        
    if(InString[currentIndex + numIndex1 + 4] != ',') return checkIndex;
    checkIndex;
        
    if(!stoi(std::string{InString[currentIndex + numIndex1 + 5]})) return checkIndex;

    int numIndex2 = 0;
    std::string inNum2;
    std::string charStr2{InString[currentIndex + numIndex1 + 5 + numIndex2]};
    while(std::any_of(charStr2.begin(), charStr2.end(), ::isdigit))
    {
        inNum2.push_back(InString[currentIndex + numIndex1 + 5 + numIndex2]);
        numIndex2++;
        charStr2 = std::string{InString[currentIndex + numIndex1 + 5 + numIndex2]};
    }
    checkIndex += numIndex2;
        
    if(InString[currentIndex + numIndex1 + 5 + numIndex2] != ')') return checkIndex;

    Elements.emplace_back(std::stoi(inNum1), std::stoi(inNum2));
    return ++checkIndex;
}