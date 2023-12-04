#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string inString;
    std::ifstream inFile("inputday1.txt");

    int sum = 0;
    int maxSum[3]{0,0,0};

    while(std::getline(inFile, inString))
    {
        if(inString != "")
        {
            sum += std::stoi(inString);
        }
        else
        {
            if(sum >= maxSum[0]) maxSum[0] = sum;
            else if(sum >= maxSum[1]) maxSum[1] = sum;
            else if(sum >= maxSum[2]) maxSum[2] = sum;

            // bubble sort
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(maxSum[i] > maxSum[j])
                    {
                        int temp = maxSum[i];
                        maxSum[i] = maxSum[j];
                        maxSum[j] = temp;
                    }
                }
            }
            sum = 0;
        }
    }
    std::cout << maxSum[0] + maxSum[1] + maxSum[2] << "\n";

    system("pause");

    return 0;
}