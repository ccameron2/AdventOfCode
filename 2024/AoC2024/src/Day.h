#pragma once
#include <vector>

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
