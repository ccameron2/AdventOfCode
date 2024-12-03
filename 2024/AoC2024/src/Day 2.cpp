#include "Day.h"
#include <fstream>
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
    for(auto& report : ReportList) if(TestReport(report,false)) safeReports++;

    std::cout << "Result: " << safeReports << std::endl;

    safeReports = 0;
    for(auto& report : ReportList) if(TestReport(report, true)) safeReports++;
    
    std::cout << "Result: " << safeReports << std::endl;
}

bool Day2::TestReport(std::vector<int>& report, bool allowTolerance)
{
    bool safe = true;
    int toleranceIndex = 0;
    bool descending = false;
    if(report[0] > report[1]) descending = true;
       
    for(int i = 0; i < report.size() - 1; i++)
    {
        if(descending && report[i] < report[i + 1])
        {
            if(allowTolerance)
            {
                toleranceIndex = i;
            }
            safe = false;
            break;
        }
        if(!descending && report[i] > report[i + 1])
        {
            if(allowTolerance)
            {
                toleranceIndex = i;
            }
            safe = false;
            break;
        }
        int a  = std::max(report[i],report[i + 1]);
        int b  = std::min(report[i],report[i + 1]);
            
        int difference = a - b;
        if(difference < 1 || difference > 3)
        {
            if(allowTolerance)
            {
                toleranceIndex = i;
            }
            safe = false;
            break;
        }
    }
    
    if(!safe && allowTolerance)
    {
        std::vector<int> toleranceReport;
        for(int i = 0; i < report.size(); i++)
        {
            if(i == toleranceIndex) continue;
            toleranceReport.push_back(report[i]);
        }
        safe = TestReport(toleranceReport, false);
    }
    
    return safe;
}
