#include <iostream>

#include "Train.h"

Train::Train(const int &inTrainNumber) : trainNumber(inTrainNumber) {
    do {
        std::cout << "Enter travel time in seconds for train #" << inTrainNumber << ": ";
        std::cin >> travelTime;
    }
    while (travelTime < 1);
}

int Train::getTrainNumber() const {
    return trainNumber;
}

int Train::getTravelTime() const {
    return travelTime;
}


