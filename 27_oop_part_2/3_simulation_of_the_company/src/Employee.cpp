#include "Employee.h"

void Employee::setName(std::string &inName) {
    fullName = inName;
}

std::string Employee::getName() {
    return fullName;
}

void Employee::setRandomName() {
    fullName = firstNames[rand() % firstNames.size()] + " " + secondNames[rand() % secondNames.size()];
}

std::vector<std::string> Employee::firstNames = {"Noah", "Mark", "Liam", "William", "James", "Benjamin", "Jacob",
                                                 "Michael", "Elijah", "Emma", "Olivia", "Ava", "Sophia", "Isabella",
                                                 "Mia", "Charlotte", "Abigail", "Emily"};;
std::vector<std::string> Employee::secondNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller",
                                                  "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White",
                                                  "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson",
                                                  "Clark", "Rodriguez", "Lewis"};





