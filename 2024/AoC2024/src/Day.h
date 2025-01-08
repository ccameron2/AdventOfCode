#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <condition_variable>
#include <thread>

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
    int CheckMul(int currentIndex);
    int CheckEnabled(int currentIndex);
private:
    std::string InString;
    std::vector<std::pair<int,int>> Elements;
    bool Enabled = true;
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

class Day6 : public Day
{
    bool Init() override;
    void Run() override;
private:
    enum class Direction
    {
        North,
        East,
        South,
        West
    }; 
    struct Coord
    {
        int x;
        int y;
    };
    std::vector<std::vector<char>> Room;
    Coord CurrentCoord;
    Direction CurrentDirection = Direction::North;
    int tileCount = 0;
    std::pair<Coord,bool> MoveNorth(Coord coord);
    std::pair<Coord,bool> MoveEast(Coord coord);
    std::pair<Coord,bool> MoveSouth(Coord coord);
    std::pair<Coord,bool> MoveWest(Coord coord);
};

// Plutonian Pebbles
class Day11 : public Day
{
    bool Init() override;
    void Run() override;

private:
    struct Stone
    {
        Stone(){};
        Stone(const std::string& input) : Engraving(std::stoul(input)){}
        uint64_t Engraving;
    };
    
    static Stone Split(Stone& source);
    void BlinkThread(uint32_t thread);
    static void CheckStones(std::vector<Stone>& stones, std::vector<Stone>& newStones);

    void Blink();
    
    std::vector<Stone> Stones;

    struct WorkerThread
    {
        std::thread Thread;
        std::condition_variable WorkReady;
        std::mutex Lock;
    };

    struct BlinkWork
    {
        bool Complete = true;
        std::vector<Stone> InStones;
        uint64_t NumStones;
        std::vector<Stone> NewStones;
    };

    static const uint32_t MAX_WORKERS = 8;
    std::pair<WorkerThread, BlinkWork> BlinkWorkers[MAX_WORKERS];
    uint32_t NumWorkers;
};

// Warehouse Woes
class Day15 : public Day
{
    bool Init() override;
    void Run() override;

private:
};