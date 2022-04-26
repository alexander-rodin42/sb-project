#include "StaffMember.h"

StaffMember::StaffMember(const int &inTeamNumber) : teamNumber(inTeamNumber) {
    this->setRandomName();
    std::cout << this->getName() << std::endl;
}

int StaffMember::getCurrentTask() const {
    return currentTask;
}

void StaffMember::setCurrentTask(const int &inTask) {
    if (inTask <= 0 || inTask > 3) {
        currentTask = 0;
    } else {
        currentTask = inTask;
    }
}

void StaffMember::printCurrentTask() {
    std:: cout << this->getName() << " - ";
    if (currentTask == NONE) {
        std::cout << "not busy.";
    }
    else if (currentTask == A) {
        std::cout << "does task A.";
    }
    else if (currentTask == B) {
        std::cout << "does task B.";
    }
    else if (currentTask == C) {
        std::cout << "does task C.";
    }
    else {
        std::cout << "does not understand what.";
    }
    std::cout << std::endl;
}




