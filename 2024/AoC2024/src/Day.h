#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Day
{
public:
    virtual ~Day() = default;
    virtual bool Init() = 0;
    virtual void Run() = 0;
};

class Day1  : public Day
{
    bool Init() override;
    void Run() override;
private:
    std::vector<int> List1;
    std::vector<int> List2;
    void SortList(std::vector<int>& List);
};

class Day2  : public Day
{
    bool Init() override;
    void Run() override;
private:
    bool TestReport(std::vector<int>& report, bool allowTolerance);
    std::vector<std::vector<int>> ReportList;
};

class Day3 : public Day
{
public:
    bool Init() override;
    void Run() override;
private:
    std::string InString;
};

class Day4 : public Day
{
public:
    bool Init() override;
    void Run() override;

private:
    enum Direction
    {
        North,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest
    };
    
    struct Coord
    {
        int x;
        int y;
    };

    void Part1();
    bool IsPart1 = false;
    bool CheckDirection(Direction direction, Coord coord) const;
    bool CheckNorth(Coord coord) const;
    bool CheckEast(Coord coord) const;
    bool CheckSouth(Coord coord) const;
    bool CheckWest(Coord coord) const;
    bool CheckNorthEast(Coord coord) const;
    bool CheckSouthEast(Coord coord) const;
    bool CheckSouthWest(Coord coord) const;
    bool CheckNorthWest(Coord coord) const;

    std::vector<std::vector<char>> WordSearch;
};

class Day11 : public Day
{
    bool Init() override;
    void Run() override;

private:
    struct Stone
    {
        Stone(){};
        Stone(const std::string& input) : Engraving(input){}
        std::string Engraving;
    };

    // Split a new stone from this one
    Stone Split(Stone& source)
    {
        Stone newStone;
        for(int i = source.Engraving.length() / 2; i < source.Engraving.length(); i++)
        {
            newStone.Engraving.push_back(source.Engraving[i]);
        }
        source.Engraving.erase(source.Engraving.length() / 2);

        // correct 0s
        if(!std::stoi(source.Engraving))
        {
            source.Engraving = "0";
        }
        if(!std::stoi(newStone.Engraving))
        {
            newStone.Engraving = "0";
        }
        if(source.Engraving.size() > 1)
        {
            int index = 0;
            bool found = false;
            while(source.Engraving[index] == '0')
            {
                found = true;
                index++;
            }
            
            if(found)
            {
                source.Engraving.erase(0,index);
            }
        }
        if(newStone.Engraving.size() > 1)
        {
            int index = 0;
            bool found = false;
            while(newStone.Engraving[index] == '0')
            {
                found = true;
                index++;
            }
            
            if(found)
            {
                newStone.Engraving.erase(0,index);
            }
        }
        return newStone;
    }
    
    void Blink();
    
    std::vector<Stone> Stones;
};