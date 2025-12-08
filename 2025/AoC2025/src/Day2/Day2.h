#pragma once
#include "Util.h"

struct Range
{
	Range(int low, int high) : Low(low), High(high)
	{
		Count = high - low;
	}
	int Low;
	int High;
	int Count = 0;
};

class Day2 : public Day
{
public:
	Day2();
	
};
