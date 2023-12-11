#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;

int charToInt(char ch)
{
    return ch - '0';
}

int main()
{
    string inLine;
    std::ifstream inFile("inputVal.txt");
    std::vector<std::vector<char>> inputGrid;
    while (std::getline(inFile, inLine))
    {
        std::stringstream strStream(inLine);
        std::vector<char> newGridLine;

        // Read grid in as chars
        for (auto &ch : inLine)
        {
            newGridLine.push_back(ch);
        }
        inputGrid.push_back(newGridLine);
    }

    for (int i = 0; i < inputGrid.size(); i++)
    {
        for (int j = 0; j < inputGrid[i].size(); j++)
        {
            char ch = inputGrid[i][j];
            if (ch == '*' || ch == '#' || ch == '+' || ch == '$' || ch == '-' || ch == '=' || ch == '/' || ch == '@' || ch == '%' || ch == '&')
            {
                // Check for numbers N,NE,E,SE,S,SW,W,NW and add them

                // NW
                // if(NW is a number)
                // read full number
                // add to total
                if (inputGrid[i - 1][j])
            }
        }
    }

    return 0;
}