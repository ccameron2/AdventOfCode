#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;

enum class NearType
{
    Number,
    Symbol,
    Dot
};

int CharToInt(char ch)
{
    int res = ch - '0';
    if(res > 0)
    {
        return res;
    }
    return 0;
}


NearType CheckNear(char near)
{
    if(near == '.')
    {
        return NearType::Dot;
    }
    if(isdigit(near))
    {
        return NearType::Number;
    }
    else if(near == ' ')
    {
        return NearType::Dot;
    }
    else
    {
        return NearType::Symbol;
    };
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
    auto previousResult = NearType::Dot;
    int sum = 0;
    for (int i = 0; i < inputGrid.size(); i++)
    {
        for (int j = 0; j < inputGrid[i].size(); j++)
        {
            char ch = inputGrid[i][j];
            if (isdigit(ch))
            {
                bool addToTotal = true;
                bool multiNumber = false;
                string multiNum = "";

                char W = ' ',NW = ' ',SW = ' ',N = ' ',S = ' ',E = ' ',NE = ' ',SE = ' ';
                int sizei =  inputGrid.size() - 1;
                int sizej = inputGrid[i].size();
                if(j != 0) N = inputGrid[i][j - 1];
                if(j != 0 && i < sizei) NE = inputGrid[i + 1][j - 1];
                if(i != 0 && j != 0) NW = inputGrid[i - 1][j - 1];
                if(i != 0) W = inputGrid[i - 1][j];
                if(i != 0 && j < sizej) SW = inputGrid[i - 1][j + 1];            
                if(j < sizej) S = inputGrid[i][j + 1];
                if(i < sizei) E = inputGrid[i + 1][j];
                if(i < sizei && j < sizej)SE = inputGrid[i + 1][j + 1];

                char NearSquares[8]{N,NE,E,SE,S,SW,W,NW};
                NearType NearResults[8];
                for(int k = 0; k < 8; k++)
                {
                    // optimise: stop checking altogether if a symbol is found
                    // ideally dont read the above in at all by checking when they are read
                    NearResults[k] = CheckNear(NearSquares[k]);
                }

                for(int k = 0; k < 8; k++)
                {
                    auto result = NearResults[k];
                    if(result == NearType::Symbol)
                    {
                        addToTotal = false;
                        // Break out of the loop, the numbers are discarded
                        break;
                    }
                    else if(result == NearType::Number)
                    {
                        if(NearResults[6] == result)
                        {   
                            addToTotal = false;
                            break;
                        } // Break out of the loop, numbers have already been read as a multinumber
                        
                        int steps = 1;
                        bool stepping = true;
                        multiNum += ch;
                        // Find direction it's in and check the next ones until a dot is found to find end of number
                        while(stepping)
                        {
                            auto input = inputGrid[i][j + steps];
                            if(CheckNear(input) != NearType::Dot)
                            {
                                multiNum += input;
                                steps += 1;
                            }
                            else
                            {
                                stepping = false;
                            }                      
                        }
                    }
                    else if(result == NearType::Dot)
                    {
                        // continue
                    }
                }

                if(addToTotal)
                {
                    // Add the number as it is finished, but only after all results have been checked;
                    if(!multiNumber){sum += CharToInt(ch);}
                    else
                    {
                        sum += std::stoi(multiNum); 
                    } 
                }
                multiNum = "";
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}