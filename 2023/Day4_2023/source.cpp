#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;

struct Card
{
    int Id = 0;
    std::vector<int> WinningNumbers;
    std::vector<int> Numbers;
};

std::vector<Card> ReadCards(string path)
{
    std::vector<Card> cards;
    string inString, inLine;
    std::ifstream inFile(path);

    while(std::getline(inFile,inLine))
    {
        std::stringstream strStream(inLine);
        while (strStream >> inString && strStream)
        {
            if (inString == "Card")
            {
                Card newCard;
                bool winningNumsRead = false;

                strStream >> inString;

                inString.pop_back();           
                newCard.Id = std::stoi(inString);

                for(int i = 0; i < 2; i++)
                {
                    std::vector<int> inNumbers;
                    strStream >> inString;
                    while(inString != "|");
                    {         
                        strStream >> inString;
                        if(inString == "|") break;                   
                        inNumbers.push_back(std::stoi(inString));                
                    }
                    

                    if(i == 0) newCard.WinningNumbers = inNumbers;
                    else newCard.Numbers = inNumbers;
                }
                cards.push_back(newCard);
            }
        }
        
    }
    return cards;
}

int ProcessCards(std::vector<Card> cards)
{
    int score = 0;
    for(auto& card : cards)
    {
        int numMatching = 0;
        for(auto& num : card.Numbers)
        {
            for(int i = 0; i < card.WinningNumbers.size(); i++)
            {
                if(num == card.WinningNumbers[i])
                {
                    ++numMatching;
                }
            }           
        }
        int cardScore = 0;
        for(int i = 0; i < numMatching; i++)
        {
            if(i == 0) cardScore = 1;
            else cardScore *= 2;
        }
    }
    return score;
}

int main()
{
    std::vector<Card> cards = ReadCards("inputVal.txt");

    int score = ProcessCards(cards);

    std::cout << "Score : " << score << std::endl;

    system("pause");
    return 0;
}