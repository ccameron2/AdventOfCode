#include <iostream>
#include <fstream>
#include <string>

using std::string;

int charToInt(char ch){
    return ch - '0';
}

int main()
{
    string inString;
    std::ifstream inFile("input.txt");
    int idSum = 0;

    while(inFile >> inString)
    {
        if(inString == "Game")
        {
            // Get ID
            inFile >> inString;
            idSum += charToInt(inString[0]);
            
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