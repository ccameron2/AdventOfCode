#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;

int RockPaperScissors(string a, string b)
{
    int score = 0;
    if (a == "A")
    {
        if (b == "X")
        {
            score += 4;
        }
        else if (b == "Y")
        {
            score += 8;
        }
        else if (b == "Z")
        {
            score += 3;
        }
    }
    else if (a == "B")
    {
        if (b == "X")
        {
            score += 1;
        }
        else if (b == "Y")
        {
            score += 5;
        }
        else if (b == "Z")
        {
            score += 9;
        }
    }
    else if (a == "C")
    {
        if (b == "X")
        {
            score += 7;
        }
        else if (b == "Y")
        {
            score += 2;
        }
        else if (b == "Z")
        {
            score += 6;
        }
    }
    return score;
}

int main()
{
    std::ifstream inFile("input.txt");
    string a, b;
    int score = 0;
    while (inFile >> a >> b)
    {
        if (a == "A" && b == "X")

            score += RockPaperScissors(a, b);
    }
    std::cout << score;
    return 0;
}