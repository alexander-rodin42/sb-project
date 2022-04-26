#include <iostream>
#include <ctime>

#include "CompanyHead.h"

int main() {
    std::srand(std::time(nullptr));
    auto* companyHead = new CompanyHead();

    do {
        companyHead->setTask();
    }
    while ( !companyHead->checkTeamsBusy());

    delete companyHead;
    return 0;
}
