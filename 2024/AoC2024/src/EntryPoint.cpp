#include <iostream>
#include "Day.h"

int main()
{
    std::cout << "Enter day\n";
    
    int input = 0;
    std::cin >> input;
    
    std::unique_ptr<Day> selectedDay;
    switch(input)
    {
        case 1:
            selectedDay = std::make_unique<Day1>();
            break;
        default:
            break;
    }
    
    if(!selectedDay->Init()) std::cout << "Error during initialisation";
}