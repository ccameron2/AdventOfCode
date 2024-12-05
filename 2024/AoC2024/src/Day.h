#pragma once
#include <vector>
#include <string>

class Day
{
public:
    virtual ~Day() = default;
    virtual bool Init() = 0;
    virtual void Run() = 0;
};

class Day1  : public Day
{
    bool Init() override;
    void Run() override;
private:
    std::vector<int> List1;
    std::vector<int> List2;
    void SortList(std::vector<int>& List);
};

class Day2  : public Day
{
    bool Init() override;
    void Run() override;
private:
    bool TestReport(std::vector<int>& report, bool allowTolerance);
    std::vector<std::vector<int>> ReportList;
};

class Day3 : public Day
{
public:
    bool Init() override;
    void Run() override;
private:
    std::vector<std::string> InList;
};

class Day4 : public Day
{
public:
    bool Init() override;
    void Run() override;
private:
};