#include "Day.h"

#include <iostream>
#include <string>


bool Day3::Init()
{
    std::fstream inFile("../../../AoC2024/input/input3test.txt");
    std::string inStr;
    if(inFile)
    {
        inFile >> inStr;
        for(char &c : inStr)
        {
            std::string newString;
            newString.push_back(c);
            InList.push_back(newString);
        }
        return true;
    }
    return false;
}

void Day3::Run()
{
    std::vector safeChars{"m","u","l","(",",",")"};
    std::vector<std::string> output;
    int indicesChecked;
    for(int i = 0; i < InList.size(); i+= indicesChecked)
    {
        std::string outputString;
        indicesChecked = 0;
        int safeIndex = 0;
        
        bool failed = false;
        while(!failed)
        {
            if(i + indicesChecked >= InList.size()) // reached end of file
            {
                break;
            }
            if(indicesChecked == 4) // must be a number to pass
            {
                while(std::stoi(InList[i + indicesChecked]))
                {
                    InList.push_back(InList[i + indicesChecked]);
                    indicesChecked++;
                }
                if(InList[indicesChecked] == safeChars[safeIndex]) // must be a comma to pass
                {
                    safeIndex++;
                    indicesChecked++;
                    while(std::stoi(InList[i + indicesChecked]))
                    {
                        InList.push_back(InList[i + indicesChecked]);
                        indicesChecked++;
                    }
                }
            }
            failed = InList[i + indicesChecked] != safeChars[safeIndex];
            indicesChecked++;
            if(failed) break;
            outputString.push_back(*InList[i + indicesChecked].data());
            safeIndex++;
        }
        
        if(!outputString.empty()) { output.push_back(outputString); }
    }
}
