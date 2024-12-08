#include "Day.h"
#include <iostream>
#include <sstream>
#include <string>

bool Day2::Init()
{
    std::ifstream inFile("../../../AoC2024/input/input2.txt");
    if(inFile.is_open())
    {
        std::string inLine;
        while(std::getline(inFile,inLine))
        {
            std::vector<int> Report;
            std::stringstream ss(inLine);
            std::string ch;
            while(ss >> ch)
            {
                Report.push_back(std::stoi(ch));
            }
            ReportList.push_back(Report);
        }
        return true;
    }
    return false;
}

void Day2::Run()
{
    int safeReports = 0;
    for(auto& report : ReportList) if(TestReport(report, false)) safeReports++;

    std::cout << "Result: " << safeReports << std::endl;

    safeReports = 0;
    for(auto& report : ReportList) if(TestReport(report, true)) safeReports++;
    
    std::cout << "Result: " << safeReports << std::endl;
}

bool Day2::TestReport(std::vector<int>& report, bool allowTolerance)
{
    bool safe = true;
    bool descending = false;
    if(report[0] > report[1]) descending = true;
       
    for(int i = 0; i < report.size() - 1; i++)
    {
        // if no longer all ascending / descending
        if(descending && report[i] < report[i + 1])
        {
            safe = false;
            break;
        }
        if(!descending && report[i] > report[i + 1])
        {
            safe = false;
            break;
        }

        // if difference is greater than 3 or less than 1
        int a  = std::max(report[i],report[i + 1]);
        int b  = std::min(report[i],report[i + 1]);
        
        int difference = a - b;
        if(difference < 1 || difference > 3)
        {
            safe = false;
            break;
        }
    }

    // if failed the first time, call again removing a different element each time
    if(!safe && allowTolerance)
    {
        for(int i = 0; i < report.size(); i++)
        {
            // make new list with element removed
            std::vector<int> toleranceReport;
            toleranceReport.resize(report.size() - 1);
            int index = 0;
            for(int j = 0; j < report.size(); j++)
            {
                if(j == i) continue;
                toleranceReport[index] = report[j];
                index++;
            }
            safe = TestReport(toleranceReport, false);
            if(safe) break;
        }
    }
    
    return safe;
}