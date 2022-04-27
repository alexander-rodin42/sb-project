#include <iostream>
#include <map>
#include <thread>
#include <mutex>

#include "Swimmer.h"

std::map<double, Swimmer*> tableResults;
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
    tableResults[timeInSeconds] = swimmer;
    table_results_access.unlock();

    swimmer->finish();
}

bool check_swim_is_over (const int& trackCount, Swimmer** tracks) {
    for (int i = 0; i < trackCount; ++i) {
        if (!tracks[i]->checkFinish()) {
            return false;
        }
    }
    return true;
}

int main() {
    const int trackCount = 6;
    auto* swimmers = new Swimmer*[trackCount];

    for (int i = 0; i < trackCount; ++i) {
        std::cout << "Track #" << i + 1 << std::endl;
        swimmers[i] = new Swimmer();
    }

    for (int i = 0; i < trackCount; ++i) {
        std::thread start(swim, swimmers[i]);
        start.detach();
    }

    while ( !check_swim_is_over(trackCount, swimmers)) {}

    std::cout << "Swim results:" << std::endl;
    table_results_access.lock();
    for (auto & i : tableResults) {
        std::cout << i.second->getName() << " - " << i.first << " seconds."  << std::endl;
    }
    table_results_access.unlock();

    delete[] swimmers;
    return 0;
}
