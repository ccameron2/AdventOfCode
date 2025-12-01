#pragma once

#include "Util.h"

class Day1 : public Day
{
public:
    Day1();
};

class Safe
{
public: 
    Safe() = default;
    void NextCombination(int dir, int position);
    void PrintResult();
private:
    int CurrentPosition = 50;
    int NumTimesZero = 0;
    int TopValue = 100;
};