#include "rand-range.h"

RandRange::RandRange() : RandInt()
{
}

RandRange::RandRange(int low, int high)
    : RandInt(), _low(low), _high(high)
{
}

RandRange::RandRange(int seed, int low, int high)
    : RandInt(seed), _low(low), _high(high)
{
}

RandRange::~RandRange()
{}

void RandRange::gen(int n)
{
    int range = _high - _low + 1;

    srand(_seed);
    for (int i=0; i<n; ++i) {
        double x = _low + rand() % range;
        _numbers.push_back(x);
    }
}

ostream& operator<<(ostream& os, const RandRange& r)
{   
    os << (const RandInt&) r;
    return os;
}

