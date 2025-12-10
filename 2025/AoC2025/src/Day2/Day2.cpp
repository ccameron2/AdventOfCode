#include "Day2.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool CompareNumVecs(std::vector<int> a, std::vector<int> b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

// returns true if repeating
bool CheckDigits(int numDigits, std::vector<int>& number)
{
	int numTimesCanContain = number.size() / numDigits;
	
	std::vector<std::vector<int>> combinations;
	for (int i = 0; i < numTimesCanContain; i++)
	{
		combinations.push_back(std::vector<int>());
		for (int j = 0; j < numDigits; j++)
		{
			combinations[i].push_back(number[i * numDigits + j]);
		}
	}
	
	for (auto& combination : combinations)
	{
		if (!CompareNumVecs(combination, combinations[0]))
		{
			return false;
		}
	}
	return true;
}

Day2::Day2()
{
	std::vector<std::string> InputStrings;
	
	std::ifstream file("example2.txt");

	if (file.is_open()) 
	{
		std::string line;
		while (std::getline(file, line)) 
		{
			std::stringstream ss(line);
			std::string segment;
			while (std::getline(ss, segment, ','))
			{
				InputStrings.push_back(segment);
			}
		}
	}
	file.close();
	
	std::vector<Range> Ranges;
	for (auto& str : InputStrings)
	{
		std::stringstream ss(str);
		std::string lowSegment;
		std::string highSegment;
		std::getline(ss, lowSegment, '-');
		std::getline(ss, highSegment);
		Ranges.emplace_back(Range(lowSegment, highSegment));
	}
	
	std::vector<uint64_t> invalidIDs;
	for (auto& range : Ranges)
	{
		for (auto& number : range.Numbers)
		{
			uint64_t count = number.size();
			uint64_t maxRep = count / 2;
			
			if (false)
			{
				std::vector<int> testVec1;
				for (int i = 0; i < maxRep; i++)
				{
					testVec1.push_back(number[i]);
				}
			
				std::vector<int> testVec2;
				for (int i = maxRep; i < count; i++)
				{
					testVec2.push_back(number[i]);
				}
			
				if (CompareNumVecs(testVec1, testVec2))
				{
					std::ostringstream os;
					for (auto& num : number)
					{
						os << num;
					}
					invalidIDs.push_back(std::stoll(os.str()));	
				}
			}
			
			bool valid = true;
			for (int i = maxRep; i > 0; i--)
			{
				if (number.size() % i != 0)
				{
					continue;
				}
				if (CheckDigits(i, number))
				{
					valid = false;
					break;
				}
			}
			
			if (valid == false)
			{
				std::ostringstream os;
				for (auto& num : number)
				{
					os << num;
				}
				uint64_t id = std::stoll(os.str());
				invalidIDs.push_back(id);	
			}
		}
	}
	
	uint64_t result = 0;
	for (auto& id : invalidIDs)
	{
		result += id;
	}
	
	std::cout << "Result: " << result << std::endl;
	
}