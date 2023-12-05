#include <iostream>
#include <fstream>
#include <string>

using std::string;

int charToInt(char ch)
{
    return ch - '0';
}

int main()
{
    string inString;
    std::ifstream inFile("inputVal.txt");
    int idSum = 0;
    int id = 0;

    while (inFile >> inString)
    {
        if (inString == "Game")
        {
            bool possible = true;

            // Get ID
            inFile >> inString;
            id = charToInt(inString[0]);

            char backChar = ' ';

            bool endOfLine = false;
            int r = 0, g = 0, b = 0;
            while (!endOfLine)
            {
                // Loop through cube sets
                while (backChar != ';' && !endOfLine)
                {
                    // Read number of cubes
                    inFile >> inString;
                    int numCubes = std::stoi(inString);

                    // Read colour of cubes
                    inFile >> inString;
                    backChar = inString.back();

                    // Check back of string for separators
                    if (backChar == ';' || backChar == ',')
                    {
                        inString.pop_back();
                    }
                    else
                    {
                        endOfLine = true;
                    }

                    // Assign number to colour of cubes
                    if (inString == "red")
                    {
                        r += numCubes;
                    }
                    else if (inString == "green")
                    {
                        g += numCubes;
                    }
                    else if (inString == "blue")
                    {
                        b += numCubes;
                    }
                }

                // Check if game is possible then reset
                if (r > 12)
                    possible = false;
                else if (g > 13)
                    possible = false;
                else if (b > 14)
                    possible = false;
                r = 0, g = 0, b = 0;
                backChar = ' ';
            }

            // Add id if game is possible
            if (possible)
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