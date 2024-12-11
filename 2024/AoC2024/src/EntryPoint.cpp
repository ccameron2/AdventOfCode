#include <iostream>
#include "Day.h"

int main()
{
    std::cout << "Enter day\n";
    
    int input = 0;
    std::cin >> input;
    std::cout << "\n";
    
#ifdef WINDOWS
    system("cls");
#endif
    
    std::unique_ptr<Day> selectedDay;
    switch(input)
    {
        case 1:
            selectedDay = std::make_unique<Day1>();
            break;
        case 2:
            selectedDay = std::make_unique<Day2>();
            break;
        case 3:
            selectedDay = std::make_unique<Day3>();
            break;
        case 4:
            selectedDay = std::make_unique<Day4>();
            break;
        case 11:
            selectedDay = std::make_unique<Day11>();
            break;
        default:
            std::cout << "Invalid input\n";
            return 0;
    }
    
    if(selectedDay->Init()) selectedDay->Run();
    else std::cout << "Error during initialisation\n";
}