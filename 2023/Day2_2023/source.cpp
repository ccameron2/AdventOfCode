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
    std::ifstream inFile("input.txt");
    int idSum = 0;
    int id = 0;

    while (inFile >> inString)
    {
        if (inString == "Game")
        {
            // Get id and remove : separator
            inFile >> inString;
            inString.pop_back();

            id = std::stoi(inString);

            char backChar = ' ';

            bool endOfLine = false;
            int r = 0, g = 0, b = 0;
            int maxR = 0, maxG = 0, maxB = 0;
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

                // Check maximum cubes needed for this round
                if (r > maxR)
                    maxR = r;
                if (g > maxG)
                    maxG = g;
                if (b > maxB)
                    maxB = b;

                r = 0, g = 0, b = 0;
                backChar = ' ';
            }

            if (maxR == 0)
            {
                maxR = 1;
            }
            if (maxG == 0)
            {
                maxG = 1;
            }
            if (maxB == 0)
            {
                maxB = 1;
            }

            // Calculate power for this game
            int power = (maxR * maxG * maxB);
            idSum += power;

            maxR = 0, maxG = 0, maxB = 0;
        }
    }
    std::cout << "Sum: " << idSum << std::endl;
    system("pause");
    return 0;
}