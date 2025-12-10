#include "Day3.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


Day3::Day3()
{
	std::vector<Bank> Banks;
	
	std::ifstream file("input3.txt");

	if (file.is_open()) 
	{
		std::string line;
		while (std::getline(file, line)) 
		{
			Bank newBank;
			for (auto& ch : line)
			{
				newBank.push_back(ch - '0');
			}
			Banks.push_back(newBank);
		}
	}
	file.close();
	
	Bank FinalJoltages;
	for (auto& bank : Banks)
	{
		int Largest = -1;
		int SecondLargest = -1;
		for (auto& num : bank)
		{
			if (num >= Largest)
			{
				if (num != bank[bank.size() - 1])
				{
					SecondLargest = -1;
				}
				else
				{
					SecondLargest = Largest;
				}
				Largest = num;
			}
			if (num > SecondLargest && num != Largest)
			{
				SecondLargest = num;
			}
		}
		
		Bank tempBank;
		bool largestGrabbed = false;
		bool secondGrabbed = false;
		
		for (auto& num : bank)
		{
			if (num == Largest && !largestGrabbed)
			{
				tempBank.push_back(num);
				largestGrabbed = true;
			}
			if (num == SecondLargest && !secondGrabbed)
			{
				tempBank.push_back(num);
				secondGrabbed = true;
			}
		}
		std::ostringstream os;
		for (auto& num : tempBank)
		{
			os << num;
		}
		FinalJoltages.push_back(std::stoi(os.str()));
	}
	
	uint64_t result = 0;
	for (auto& joltage : FinalJoltages)
	{
		result += joltage;
	}
	
	std::cout << "Result: " << result << std::endl;
}
