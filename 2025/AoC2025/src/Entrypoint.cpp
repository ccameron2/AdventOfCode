#include "Day1/Day1.h"

#include <iostream>

int main()
{
    std::cout << "Enter day to run" << std::endl;
    int day = 0;
    std::cin >> day;

    Day* newDay = nullptr;
    switch(day)
    {
        case 1:
            newDay = new Day1();
        break;
        default:
            std::cout << "Invalid day" << std::endl;
        break;
    }

    delete newDay;
}