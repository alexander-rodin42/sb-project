#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

bool CheckName (const std::string& name) {
    for (auto i : name) {
        if (!(i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z')) {
           return false;
        }
    }
//    The IDE suggested using a "std::all_of" instead of a cycle, for me the cycle is clearer.
//    if ( !(std::all_of(name.begin(), name.end(), [](char i){return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z';}))) {
//        return false;
//    }
    return true;
}

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

bool ConfirmDateIsCorrect (const int& day, const int& month, const int& year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {
        daysInMonth[2] = 29;
    }

    if (month < 1 || month > 12) {
        std::cout << "The number of months in a year can only be from 1 to 12." << std::endl;
        return false;
    }

    if (day < 1 || day > daysInMonth[month]) {
        std::cout << "There can only be " << daysInMonth[month] << " days in the " << month << "nd month of the year ";
        std::cout << year << "." << std::endl;
        return false;
    }

    return true;
}

bool CheckDate (const std::string& date) {
    //It is taken into account that there can be no more than 4 digits in a year.

    if (date.length() != 10) {
        return false;
    }

    if (date[2] != '.' || date[5] != '.') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !(date[i] >= '0' && date[i] <= '9')) {
            return false;
        }
    }

    int day = std::stoi(date.substr(0, 2));
    int month =  std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if ( !ConfirmDateIsCorrect( day, month, year)) {
        return false;
    }

    return true;
}

bool ContinueFilling () {
    std::string userInput;

    do {
        std::cout << "Do you want to continue completing the form (yes/no)?" << std::endl;
        std::cin >> userInput;
    }
    while ( !(userInput == "yes" || userInput == "no"));

    if (userInput == "yes") {
        return true;
    }
    else {
        return false;
    }
}

void EnteringName (const std::string& message, std::string& name) {
    do {
        std::cout << message;
        std::cin >> name;
    }
    while (!CheckName( name));
}

bool FileIsEmpty (const std::string& path) {
    std::ifstream inFile;
    inFile.open (path);

    if (inFile.is_open()) {
        long long fileSize;
        inFile.seekg(0, std::ios::end);
        fileSize = inFile.tellg();
        if (fileSize != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string folderPath;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;

    do {
        std::string firstName;
        std::string lastName;
        std::string paymentDate;
        int         amountMoney;

        // input
        EnteringName( "Enter your name: ", firstName);
        EnteringName( "Enter last name: ", lastName);
        ConvertNameToFormat( firstName);
        ConvertNameToFormat( lastName);

        do {
            std::cout << "Enter payment date (dd.mm.yyyy): ";
            std::cin >> paymentDate;
        }
        while (!CheckDate( paymentDate));

        do {
            std::cout << "Enter payout amount (greater than zero): ";
            std::cin >> amountMoney;
        }
        while (amountMoney < 1);

        // write
        std::ofstream outFile;
        outFile.open(folderPath + "\\list.txt", std::ios::app);

        if ( !FileIsEmpty( folderPath + "\\list.txt")) {
            outFile << std::endl;
        }
        outFile << firstName << " " << lastName << " " << paymentDate << " " << amountMoney;
        outFile.close();
    }
    while ( ContinueFilling());

    return 0;
}

/*
    Задание 1. Реализация записи в ведомость учёта

    В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь требуется создать
простую программу записи в эту ведомость.

    Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в
формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой
записи должен быть расположен перевод строки.

    При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл
в текстовом режиме. Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.

    Советы и рекомендации

    Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.

    Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно указанным
диапазоном символов в дате. К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц
для последующего анализа.
*/

