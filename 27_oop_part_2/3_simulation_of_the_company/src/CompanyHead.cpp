#include "CompanyHead.h"

CompanyHead::CompanyHead() {
    this->setRandomName();
    std::cout << "Head of the company - " << this->getName() << std::endl;

    do {
        std::cout << "Enter number of team: ";
        std::cin >> teamCount;
    }
    while (teamCount < 1);

    team = new Manager*[teamCount];
    std::cout << std::endl;

    for (int i = 0; i < teamCount; ++i) {
        team[i] = new Manager(i + 1);
        std::cout << std::endl;
    }
}

void CompanyHead::setTask() {
    std::cout << "Enter task number: ";
    std::cin >> taskNumber;

    this->delegateTask();
}

void CompanyHead::delegateTask() {
    assert(team != nullptr);

    for (int i = 0; i < teamCount; ++i) {
        team[i]->taskDecomposition(taskNumber);
    }
}

bool CompanyHead::checkTeamsBusy() {
    assert(team != nullptr);

    for (int i = 0; i < teamCount; ++i) {
        if (team[i]->getFreeWorkers() != 0) {
            return false;
        }
    }
    return true;
}
