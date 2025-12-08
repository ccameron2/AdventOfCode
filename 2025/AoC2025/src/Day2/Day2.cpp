#include "Day2.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
		std::string segment;
		std::getline(ss, segment, '-');
		long long low = std::stoll(segment);
		std::getline(ss, segment);
		long long high = std::stoll(segment);
		Ranges.push_back(Range(low, high));
	}
	
	for (auto& range : Ranges)
	{
		range.Count = range.High - range.Low;
	}
}
