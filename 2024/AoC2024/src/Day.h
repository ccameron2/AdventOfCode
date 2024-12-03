#pragma once

class Day
{
public:
    virtual ~Day() = default;
    virtual bool Init() = 0;
};

class Day1  : public Day
{
    bool Init() override;
};

