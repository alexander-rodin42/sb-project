#pragma once

#include <cassert>

#include "Employee.h"


enum task {
    NONE = 0,
    A = 1,
    B = 2,
    C = 3
};

class StaffMember : public Employee {
public:
    explicit StaffMember(const int& inTeamNumber);
    void setCurrentTask(const int& inTask);
    int getCurrentTask() const;
    void printCurrentTask();
private:
    int teamNumber = 0;
    int currentTask = NONE;
};

