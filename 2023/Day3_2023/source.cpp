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
    return 0;
}