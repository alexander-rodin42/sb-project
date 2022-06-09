#include <exception>
#include <ctime>

#include "Pond.h"
#include "CustomExceptions.h"

Pond::Pond() {
    sectors.resize(10, trophy::EMPTY);
    tryCounter = 0;

    std::srand(std::time(nullptr));
    sectors[rand() % 9] = trophy::FISH;

    int bootsCounter = 0;
    while (bootsCounter < 3) {
        int sector = rand() % 9;

        if (sectors[sector] == trophy::EMPTY) {
            sectors[sector] = trophy::BOOT;
            ++bootsCounter;
        }
    }
}

void Pond::print() const {
    for (auto & i : sectors) {
        std::cout << int(i) << " ";
    }
    std::cout << std::endl;
}

void Pond::castFishingRod(const int &sector) {
    if (sector <= 0 || sector > 10) {
        throw std::invalid_argument("Invalid sector number.");
    }

    if (sectors[sector - 1] == trophy::EMPTY) {
        ++tryCounter;
        throw SectorIsEmpty();
    }
    else if (sectors[sector - 1] == trophy::FISH) {
        ++tryCounter;
        throw FishCaughtInTheSector();
    }
    else {
        throw BootCaughtInTheSector();
    }
}

int Pond::getTryCounter() const {
    return tryCounter;
}
