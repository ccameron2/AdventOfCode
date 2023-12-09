#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;

struct Card
{
    Card()
    {
    };
    Card(Card* card)
    {
        Id = card->Id;
        WinningNumbers = card->WinningNumbers;
        Numbers = card->Numbers;
    }
    int Id = 0;
    std::vector<int> WinningNumbers;
    std::vector<int> Numbers;
};

class CardGame
{

private:

int Copies = 0;
std::vector<Card> InCards;

public:

CardGame(string inputFile)
{
    InCards = ReadCards(inputFile);
    
    ProcessCards();
    std::cout << "Copies : " << Copies << std::endl;
};

private:

std::vector<Card> ReadCards(string path)
{
    string inString, inLine;
    std::ifstream inFile(path);
    std::vector<Card> inCards;

    while(std::getline(inFile,inLine))
    {
        std::stringstream strStream(inLine);
        while (strStream >> inString && strStream)
        {
            if (inString == "Card")
            {
                Card newCard;              
                strStream >> inString;

                inString.pop_back();           
                newCard.Id = std::stoi(inString);

                for(int i = 0; i < 2; i++)
                {
                    std::vector<int> inNumbers;
                    while (strStream >> inString)
                    {
                        if (inString == "|") break;
                        inNumbers.push_back(std::stoi(inString));
                    }
                    if(i == 0) newCard.WinningNumbers = inNumbers;
                    else newCard.Numbers = inNumbers;
                }
                inCards.push_back(newCard);
            }
        }     
    }
    Copies = inCards.size();
    return inCards;
}

void ProcessCard(Card card)
{
    std::vector<Card> cardStack;
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
    for(int i = 0; i < numMatching; i++)
    {
        cardStack.push_back(InCards[card.Id + i]);
        ++Copies;
    }

    for(auto card : cardStack)
    {
        ProcessCard(card);
    }
}

void ProcessCards()
{
    for(auto& card : InCards)
    {
        ProcessCard(card);
    }
}
};

int main()
{
    CardGame game("input.txt");

    system("pause");

    return 0;
}