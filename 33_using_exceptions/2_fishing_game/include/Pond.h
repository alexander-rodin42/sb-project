#pragma once

#include <iostream>
#include <vector>

enum class trophy {
    EMPTY,
    FISH,
    BOOT
};

class Pond {
public:
    explicit Pond();

    void print() const;
    void castFishingRod (const int& sector);
    int getTryCounter() const;

private:
    std::vector<trophy> sectors;
    int tryCounter;
};

