#include <iostream>

#include "Manager.h"

Manager::Manager(const int &inTeamNumber) : teamNumber(inTeamNumber) {
    this->setRandomName();
    std::cout << "Team Manager #" << inTeamNumber << " - " << this->getName() << std::endl;

    do {
        std::cout << "Enter the number of employees in team #" << inTeamNumber << ": ";
        std::cin >> workersCount;
    }
    while (workersCount < 1);

    workers = new StaffMember*[workersCount];
    std::cout << "Team workers #" << inTeamNumber <<":" << std::endl;

    for (int i = 0; i < workersCount; ++i) {
        std::cout << i + 1 << " ";
        workers[i] = new StaffMember(inTeamNumber);
    }
}

int Manager::getFreeWorkers() {
    assert(workers != nullptr);

    int result = 0;
    for (int i = 0; i < workersCount; ++i) {
        if (workers[i]->getCurrentTask() == NONE) {
            ++result;
        }
    }
    return result;
}

void Manager::taskDecomposition(const int &inTask) {
    std::srand(inTask + teamNumber);

    int freeWorkers = getFreeWorkers();
    if (freeWorkers > 0) {
        taskCount = 1 + rand() % freeWorkers;
    }


    this->allocateTasks();
}

void Manager::allocateTasks() {
    assert(workers != nullptr);

    std::cout << "Team Manager #" << teamNumber << " - " << this->getName() << " assigned tasks:" << std::endl;

    for (int i = 0; i < workersCount; ++i) {
        if (workers[i]->getCurrentTask() == NONE && taskCount > 0) {
            workers[i]->setCurrentTask(1 + rand() % 3);
            --taskCount;
        }
        std::cout << i + 1 << " ";
        workers[i]->printCurrentTask();
    }
    std::cout << std::endl;
}


