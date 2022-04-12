#include <iostream>

#include "MobilePhone.h"

void InputCommand (std::string& command) {
    do {
        std::cout << "> Enter the command: ";
        std::cin >> command;
    }
    while (!(command == "add" ||
             command == "call" ||
             command == "sms" ||
             command == "exit"));
}

void FindContact (MobilePhone& mobilePhone, const std::string& command) {
    std::string contact;

    do {
        std::cout << "Enter the contact's name or number: ";
        (std::cin >> contact).get();
    }
    while (!(CheckName(contact) || CheckPhoneNumber(contact)));

    if (CheckPhoneNumber(contact)) {
        ConvertNameToFormat(contact);
        if (command == "call") {
            mobilePhone.call(contact);
        }
        else {
            mobilePhone.sms(contact);
        }
    }
    else {
        mobilePhone.print( contact);
    }
}

int main() {
    MobilePhone mobilePhone;
    std::string command;

    std::cout << "Available commands: add, call, sms, exit." << std::endl;

    do {
        InputCommand( command);

        if (command == "add") {
            mobilePhone.add();
        }
        else if (command == "call" || command == "sms") {
            FindContact(mobilePhone, command);
        }
    }
    while (command != "exit");

    return 0;
}
