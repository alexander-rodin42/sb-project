#include "Person.h"
#include "Verification.h"

std::string Person::getName() {
    return name;
}

std::string Person::getPhoneNumber() {
    return phoneNumber;
}

void Person::setParameters() {
    this->setName();
    this->setPhoneNumber();
}

void Person::setName() {
    do {
        std::cout << "Enter name: ";
        (std::cin >> name).get();
    }
    while (!CheckName( name));

    ConvertNameToFormat(name);
}

void Person::setPhoneNumber() {
    do {
        std::cout << "Enter phone number: ";
        (std::cin >> phoneNumber).get();
    }
    while (!CheckPhoneNumber( phoneNumber));
}






