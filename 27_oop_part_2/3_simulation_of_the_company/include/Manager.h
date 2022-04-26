#pragma once

#include "Employee.h"
#include "StaffMember.h"

class Manager : public Employee {
public:
    explicit Manager(const int& inTeamNumber);
    int getFreeWorkers();
    void taskDecomposition(const int& inTask);
private:
    int teamNumber = 0;
    int taskCount = 0;
    int workersCount = 0;
    StaffMember** workers = nullptr;

    void allocateTasks();
};

