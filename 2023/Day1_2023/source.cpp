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
       // string alphabeticalNumber = "";
        for (string::iterator it = inString.begin(); it != inString.end(); ++it)
        {
            if (std::isdigit(*it))
            {
                twoDigitNum += *it;
                break;
            }
            else
            {
                //string str = " ";
                //str[0] = *it;
                //alphabeticalNumber.append(str);
                //auto a = inString.find("nine");
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