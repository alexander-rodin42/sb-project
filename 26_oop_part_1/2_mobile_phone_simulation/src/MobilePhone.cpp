#include <string>

#include "MobilePhone.h"
#include "Verification.h"

void MobilePhone::add() {
    Person person;
    person.setParameters();

    phoneNumberBook[person.getPhoneNumber()] = person;
    nameBook[person.getName()].push_back(person);
}

void MobilePhone::call(const std::string &phoneNumber) {
    if (phoneNumberBook.find(phoneNumber) != phoneNumberBook.end()) {
        std::cout << "CALL " << phoneNumberBook[phoneNumber].getPhoneNumber() << std::endl;
    }
    else {
        std::cout << "(!) " << phoneNumber << " number not found." << std::endl;
    }
}

void MobilePhone::sms(const std::string &phoneNumber) {
    if (phoneNumberBook.find(phoneNumber) != phoneNumberBook.end()) {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        std::cout << "Message: " << message << std::endl;
        std::cout << "Sent to number: " << phoneNumberBook[phoneNumber].getPhoneNumber() << std::endl;
    }
    else {
        std::cout << "(!) " << phoneNumber << " number not found." << std::endl;
    }
}

void MobilePhone::print(std::string &name) {
    ConvertNameToFormat( name);
    if (nameBook.find( name) != nameBook.end()) {
        std::cout << "Found " << nameBook[name].size() << " contacts named " << name << ":" << std::endl;
        for (auto & i : nameBook[name]) {
            std::cout << i.getPhoneNumber() << std::endl;
        }
    }
    else {
        std::cout << "(!) Contact with name " << name << " not found." << std::endl;
    }
}
