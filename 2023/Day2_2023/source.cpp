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
    std::ifstream inFile("inputVal.txt");
    int idSum = 0;

    while(inFile >> inString)
    {
        if(inString == "Game")
        {
            // Get ID
            inFile >> inString;
            idSum += charToInt(inString[0]);
            
            char backChar = ' ';

            int r = 0, g = 0, b = 0;

            while(backChar != ';')
            {        
                inFile >> inString;

                int numCubes = std::stoi(inString);

                inFile >> inString;
               
                backChar = inString.back(); 
                inString.pop_back();

                if(inString == "red")
                {
                    r += numCubes;
                }
                else if(inString == "green")
                {
                    g += numCubes;
                }
                else if(inString == "blue")
                {
                    b += numCubes;
                }
            }
            
        }
    }
    std::cout << "Sum: " << idSum << std::endl;
    system("pause");
    return 0;
}