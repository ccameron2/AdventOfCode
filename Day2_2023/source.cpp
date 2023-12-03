#include <iostream>
#include <fstream>
#include <string>

using std::string;

int main()
{
    string inString;
    std::ifstream inFile("input.txt");
    int idSum = 0;

    while(inFile >> inString)
    {
        if(inString == "Game")
        {
            inFile >> inString;
            idSum += std::stoi();
            int r,g,b;
            while(inString != ";")
            {
                inFile >> inString;
            }
        }
    }
    std::cout << "Sum: " << idSum << std::endl;
    system("pause");
    return 0;
}