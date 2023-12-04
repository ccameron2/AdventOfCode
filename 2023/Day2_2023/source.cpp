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
    int id = 0;

    while(inFile >> inString)
    {
        bool possible = true;
        if(inString == "Game")
        {
            // Get ID
            inFile >> inString;
            id = charToInt(inString[0]);
            
            char backChar = ' ';
            string backStr = " ";
            backStr[0] = backChar;

            int r = 0, g = 0, b = 0;
            while(backStr != "\n")
            {
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

                // Check if game is possible then reset
                if      (r > 12) possible = false; 
                else if (g > 13) possible = false; 
                else if( b > 14) possible = false;
                r = 0, g = 0, b = 0;
            }
            if(possible)
            {
                idSum += charToInt(inString[0]);
                possible = true;
            }                     
        }
        
    }
    std::cout << "Sum: " << idSum << std::endl;
    system("pause");
    return 0;
}