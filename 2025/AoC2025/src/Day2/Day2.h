#pragma once
#include <locale>
#include <sstream>
#include <string>
#include <vector>

#include "Util.h"

struct Range
{
	Range(std::string low, std::string high) : Low(low), High(high)
	{
		Count = std::stoll(high) - std::stoll(low);
		Numbers.reserve(Count);
		for (uint64_t i = 0; i <= Count; i++)
		{
			uint64_t number = std::stoll(low) + i;
			std::ostringstream os;

			os << number;
			std::string digits = os.str();
			std::vector<int> numberVec;
			for (auto& ch : digits)
			{
				numberVec.push_back(ch - '0');
			}
			
			Numbers.push_back(numberVec);
		}
	}
	std::string Low;
	std::string High;
	uint64_t Count = 0;
	std::vector<std::vector<int>> Numbers;
};

class Day2 : public Day
{
public:
	Day2();
	
};
