#include <iostream>
#include <thread>
#include <mutex>

#include "Train.h"

const int trainCount = 3;
bool stationBusy = false;
std::mutex station_access;
std::mutex message_access;

void print(Train* train, const std::string& message) {
    message_access.lock();
    std::cout << "Train #" << train->getTrainNumber() << " " << message << std::endl;
    message_access.unlock();
}

void train_departure(Train* train) {
    print(train, "started moving.");
    std::this_thread::sleep_for(std::chrono::seconds(train->getTravelTime()));

    if (stationBusy) {
        print(train, "waiting for free space.");
    }

    station_access.lock();
    stationBusy = true;

    print(train, "arrived at the stationBusy. Enter \"depart\" to leave the train from the station");
    std::string command;
    do {
        std::cin >> command;
    }
    while (command != "depart");
    print(train, "leaves from the station.");

    train->setArrived();
    stationBusy = false;
    station_access.unlock();
}

bool CheckTrainArrivals (Train** trains) {
    for (int i = 0; i < trainCount; ++i) {
        if (!trains[i]->getArrived()) {
            return false;
        }
    }
    return true;
}

int main() {
    auto* trains = new Train*[trainCount];

    for (int i = 0; i < trainCount; ++i) {
        trains[i] = new Train(i + 1);
    }

    for (int i = 0; i < trainCount; ++i) {
        std::thread start(train_departure, trains[i]);
        start.detach();
    }

    while (!CheckTrainArrivals(trains));

    delete[] trains;
    return 0;
}
