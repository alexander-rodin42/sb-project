/*
    Задание 2. Реализация программы напоминания о днях рождения

    Реализуйте простую программу по вычислению ближайшего дня рождения.

    В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: вводит имя друга и саму
дату рождения полностью, включая месяц и год, в формате год/месяц/день. Сигналом окончания ввода дней рождения является
“end” введённое в качестве имени.
    После этого программа вычисляет ближайший день рождения по отношению к текущему времени и выводит его на экран
вместе с именем в удобном, локальном формате - месяц/день. Если день рождения уже был в этом году, данные о пользователе
пропускаются. Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом.
Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.

    Советы и рекомендации
    Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

struct Person {
    std::string name{};
    std::time_t birthday{};
};

bool CheckName (const std::string& name) {
    return std::all_of(name.begin(), name.end(), [](char i){return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z';});
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

void Input (std::vector<std::map<int, std::vector<Person>>>& list) {
    std::string inputName;

    std::cout << "Enter \"end\" to complete the entry." << std::endl;
    do {
        std::time_t inputTime = 0;
        std::tm* local = std::localtime(&inputTime);
        do {
            std::cout << "Enter your friend's name: ";
            std::cin >> inputName;
        }
        while (!CheckName( inputName));

        if (inputName != "end") {
            std::cout << "Enter date of birth in the format (yyyy/mm/dd): ";
            std::cin >> std::get_time(local, "%Y/%m/%d");
            inputTime = std::mktime(local);
            ConvertNameToFormat( inputName);

            Person tempPerson;
            tempPerson.name = inputName;
            tempPerson.birthday = inputTime;

            list[local->tm_mon][local->tm_mday].push_back(tempPerson);
        }
    }
    while (inputName != "end");
}

void PrintNames (std::vector<Person>& names) {
    for (auto & i : names) {
        std::tm* local = localtime(&i.birthday);
        std::cout << i.name << ", born " << std::put_time(local, "%Y.") << std::endl;
    }
    std::cout << std::endl;
}

bool FindThisYear (const int currentDay, const int currentMonth, std::vector<std::map<int, std::vector<Person>>>& list) {
    bool nextBirthdayFound = false;

    for (int i = currentMonth; i < list.size(); ++i) {
        if (!list[i].empty()) {
            for (auto &iMap: list[i]) {
                std::tm *local = localtime(&iMap.second[0].birthday);
                if (!(i == currentMonth && iMap.first <= currentDay)) {
                    std::cout << "Next birthday " << std::put_time(local, "%m/%d") << " is:" << std::endl;
                    PrintNames(iMap.second);
                    nextBirthdayFound = true;
                    break;
                }
            }
        }
        if (nextBirthdayFound) {
            break;
        }
    }

        return nextBirthdayFound;
}

bool FindNextYear (const int currentDay, const int currentMonth, std::vector<std::map<int, std::vector<Person>>>& list) {
    bool nextBirthdayFound = false;

    for (int i = 0; i <= currentMonth; ++i) {
        if (!list[i].empty()) {
            for (auto &iMap: list[i]) {
                std::tm *local = localtime(&iMap.second[0].birthday);
                if (!(i == currentMonth && iMap.first >= currentDay)) {
                    std::cout << "Next birthday next year " << std::put_time(local, "%m/%d") << " is:" << std::endl;
                    PrintNames(iMap.second);
                    nextBirthdayFound = true;
                    break;
                }
            }
        }
        if (nextBirthdayFound) {
            break;
        }
    }

    return nextBirthdayFound;
}

void PrintNextBirthday (std::vector<std::map<int, std::vector<Person>>>& list) {
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentLocal = std::localtime(&currentTime);
    int currentMonth = currentLocal->tm_mon;
    int currentDay = currentLocal->tm_mday;

    if (!list[currentMonth].empty()) {
        for (auto & i : list[currentMonth]) {
            if (i.first == currentDay) {
                std::cout << "Today is the birthday of:" << std::endl;
                PrintNames( i.second);
            }
        }
    }

    if ( !FindThisYear(currentDay, currentMonth, list)) {
        if ( !FindNextYear(currentDay, currentMonth, list)) {
            std::cout << "Next birthday not found" << std::endl;
        }
    }
}

void PrintList (std::vector<std::map<int, std::vector<Person>>>& list) {
        for (int i = 0; i < list.size(); ++i) {
        std::cout << i + 1 << " month" << std::endl;
        if (!list[i].empty()) {
            for (auto & map : list[i]) {
                std::cout << "(" << map.first << ") day" << std::endl;
                PrintNames(map.second);
            }
        }
    }
}

int main() {
    std::vector<std::map<int, std::vector<Person>>> listOfBirthdays (12);
    Input( listOfBirthdays);
    PrintNextBirthday( listOfBirthdays);
    //PrintList( listOfBirthdays);

    return 0;
}