#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

void ConvertNameToFormat (std::string& name) {
    for (int i = 0; i < name.length(); i++){
        if (i == 0 && name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 32;
        }
        else if (i != 0 && name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        }
    }
}

bool CheckPhoneNumber (const std::string& phoneNumber) {
    if (phoneNumber.length() != 8) {
        return false;
    }
    for (int i = 0; i < 8; ++i) {
        bool hyphenIndex = i == 2 || i == 5;
        if ((hyphenIndex && phoneNumber[i] != '-') ||
            (!hyphenIndex && !(phoneNumber[i] >= '0' && phoneNumber[i] <= '9'))) {
            return false;
        }
    }
    return true;
}

bool CheckLastName (const std::string& lastName) {
    return std::all_of(lastName.begin(), lastName.end(), [](char i){return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z';});
}

void UserInput (std::string& phoneNumber, std::string& lastName) {
    std::string input;
    bool inputCorrect;

    do {
        std::cout << "Enter a request: ";

        std::getline(std::cin, input);

        if (input.empty()) {
            inputCorrect = false;
        }
        else {
            inputCorrect = true;
        }

        if (CheckLastName( input)) {
            phoneNumber = "";
            lastName = input;
            ConvertNameToFormat( lastName);
        }
        else if (CheckPhoneNumber( input)) {
            phoneNumber = input;
            lastName = "";
        }
        else if (input.length() > 9 && input[8] == ' ' &&
                 CheckPhoneNumber( input.substr(0,8)) &&
                 CheckLastName( input.substr(9,input.length() - 9))) {

            phoneNumber = input.substr(0,8);
            lastName = input.substr(9,input.length() - 9);
            ConvertNameToFormat( lastName);
        }
        else {
            std::cout << "Invalid request." << std::endl;
            inputCorrect = false;
        }
    } while (!inputCorrect);
}

void AddSubscriber (std::map<std::string, std::string>& phonebook,
                    std::map<std::string, std::vector<std::string>>& lastNameList,
                    const std::string& phoneNumber, const std::string& lastName) {

    if (phonebook.find(phoneNumber) == phonebook.end()) {
        if (lastNameList.find( lastName) == lastNameList.end()) {
            std::vector<std::string> numbers {phoneNumber};
            lastNameList.insert((std::make_pair(lastName, numbers)));
        } else {
            lastNameList.find( lastName)->second.push_back(phoneNumber);
        }

        phonebook.insert(std::make_pair(phoneNumber, lastName));

    } else {
        std::cout << "A subscriber with this number already exists."  << std::endl;
    }
}

void FindByNumber (std::map<std::string, std::string>& phonebook, const std::string& phoneNumber) {
    if (phonebook.find(phoneNumber) == phonebook.end()) {
        std::cout << "Subscriber number " << phoneNumber << " not found."  << std::endl;
    }
    else {
        std::cout << "Subscriber will be registered by number " << phoneNumber
                  << ": " << phonebook[phoneNumber] << std::endl;
    }
}

void FindByLastName (std::map<std::string, std::vector<std::string>>& lastNameList, const std::string& lastName) {
    if ((lastNameList.find(lastName) == lastNameList.end())) {
        std::cout << "Subscribers with last name " << lastName << " not found."  << std::endl;
    }
    else {
        std::cout << "Found " << lastNameList[lastName].size() << " subscribers with last name " << lastName << ":" << std::endl;
        for (auto & i : lastNameList[lastName]) {
            std::cout << i << std::endl;
        }
    }
}

void OperationSelection (std::map<std::string, std::string>& phonebook,
                         std::map<std::string, std::vector<std::string>>& lastNameList,
                         const std::string& phoneNumber, const std::string& lastName) {
    if (!phoneNumber.empty() && !lastName.empty()) {
        AddSubscriber( phonebook, lastNameList, phoneNumber, lastName);
    }
    else if (!phoneNumber.empty()) {
        FindByNumber( phonebook, phoneNumber);
    }
    else if (!lastName.empty()) {
        FindByLastName( lastNameList, lastName);
    }
}

bool Continue () {
    char userInput;

    do {
        std::cout << "Do you want to continue (y/n)?" << std::endl;
        (std::cin >> userInput).get();
        //std::cin >> userInput;  <- it works incorrectly
    }
    while ( !(userInput == 'y' || userInput == 'n'));

    if (userInput == 'y') {
        return true;
    }
    else {
        return false;
    }
}

void Print (std::map<std::string, std::string>& phonebook,
            std::map<std::string, std::vector<std::string>>& lastNameList) {

    std::cout << "--------Phonebook---------" << std::endl;
    for (auto & it : phonebook) {
        std::cout << it.first << " " << it.second << std::endl;
    }

    std::cout << "------Last mame list------" << std::endl;
    for (auto & i : lastNameList) {
        std::cout << i.first << ": " << std::endl;
        for (auto & j : i.second) {
            std::cout << j << std::endl;
        }
    }
}

int main() {
    std::string phoneNumber;
    std::string lastName;
    std::map<std::string, std::string> phonebook;
    std::map<std::string, std::vector<std::string>> lastNameList;

    do {
        UserInput (phoneNumber, lastName);
        OperationSelection( phonebook, lastNameList, phoneNumber, lastName);
    } while (Continue());

    Print(phonebook, lastNameList);
    return 0;
}

/*
    Задание 1. Телефонный справочник\

    Напишите программу «Телефонный справочник».

    На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии

    Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным номерам могут иметь
одинаковые фамилии. В таком случае на запрос 3 необходимо выдать все номера через пробелы.

    Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).
 */
