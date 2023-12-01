#include <iostream>
#include <fstream>
#include <string>

using std::string;

int main()
{
    string inString;
    std::ifstream inFile("input.txt");

    int sum = 0;
    string twoDigitNum = "";

    while (std::getline(inFile, inString))
    {
        for (string::iterator it = inString.begin(); it != inString.end(); ++it)
        {
            string alphabeticalNumber = "";
            if (std::isdigit(*it))
            {
                twoDigitNum += *it;
                break;
            }
            else
            {
                alphabeticalNumber.append(&*it);
            }
        }
        for (string::iterator it = inString.end(); it != inString.begin() - 1; --it)
        {
            if (std::isdigit(*it))
            {
                twoDigitNum += *it;
                break;
            }
        }
        std::cout << twoDigitNum << std::endl;
        sum += std::stoi(twoDigitNum);
        twoDigitNum = "";
    }

    std::cout << "Sum: " << sum << std::endl;

    system("pause");

    return 0;
}

int isAlphabeticalNumber(string input)
{
    if (input == "one")
    {
        return 1;
    }
    else if (input == "two")
    {
        return 2;
    }
    else if (input == "three")
    {
        return 3;
    }
    else if (input == "four")
    {
        return 4;
    }
    else if (input == "five")
    {
        return 5;
    }
    else if (input == "six")
    {
        return 6;
    }
    else if (input == "seven")
    {
        return 7;
    }
    else if (input == "eight")
    {
        return 8;
    }
    else if (input == "nine")
    {
        return 9;
    }
    else
    {
        return 0;
    }
}
