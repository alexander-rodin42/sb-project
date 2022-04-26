#pragma once

#include "Employee.h"
#include "Manager.h"

class CompanyHead : public Employee {
public:
    CompanyHead();
    void setTask();
    bool checkTeamsBusy();
private:
    int teamCount = 0;
    int taskNumber = 0;
    Manager** team = nullptr;

    void delegateTask();
};
