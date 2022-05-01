#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <mutex>

#include "Swimmer.h"

std::map<double, std::vector<Swimmer*>> tableResults;
std::mutex table_results_access;
std::mutex print_access;


void swim(Swimmer* swimmer) {
    double distance = 0;
    double timeInSeconds = 0;

    do {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (100 - distance > swimmer->getSpeed()) {
            distance += swimmer->getSpeed();
            ++timeInSeconds;
        } else {
            timeInSeconds += (100 - distance)/swimmer->getSpeed();
            distance = 100;
        }

        print_access.lock();
        std::cout << swimmer->getName() << " swam " << distance << " meters" << std::endl;
        print_access.unlock();

    } while (distance < 100);

    table_results_access.lock();
    tableResults[timeInSeconds].push_back(swimmer);
    table_results_access.unlock();
}

int main() {
    const int trackCount = 6;
    auto* swimmers = new Swimmer*[trackCount];
    double minSpeed = 100;
    std::vector<std::thread*> started;
    std::thread* start;

    for (int i = 0; i < trackCount; ++i) {
        std::cout << "Track #" << i + 1 << std::endl;
        swimmers[i] = new Swimmer();

        if (swimmers[i]->getSpeed() < minSpeed) {
            minSpeed = swimmers[i]->getSpeed();
        }
    }

    for (int i = 0; i < trackCount; ++i) {
        start = new std::thread(swim, swimmers[i]);
        started.push_back(start);
    }

    for (int i = 0; i < trackCount; ++i) {
        started[i]->join();
        delete started[i];
    }

    std::cout << "Swim results:" << std::endl;
    table_results_access.lock();
    for (auto & i : tableResults) {
        for (auto & j : i.second) {
            std::cout << j->getName() << " - " << i.first << " seconds." << std::endl;
        }
    }
    table_results_access.unlock();

    for (int i = 0; i < trackCount; ++i) {
        delete swimmers[i];
    }

    delete[] swimmers;

    return 0;
}
