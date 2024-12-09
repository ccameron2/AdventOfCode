#pragma once
#include <vector>
#include <string>
#include <fstream>

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