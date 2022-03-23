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

void Input (std::map<std::time_t, std::vector<std::string>>& list) {
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
            std::cout << "Enter your friend's name: ";
            std::cin >> std::get_time(local, "%Y/%m/%d");
            inputTime = std::mktime(local);
            ConvertNameToFormat( inputName);
            list[inputTime].push_back(inputName);
        }
    }
    while (inputName != "end");
}

void PrintNames (const std::vector<std::string>& names) {
    for (int i = 0; i < names.size(); ++i) {
        std::cout << i;
        if (names.size() == 1 || i == names.size() - 1) {
            std::cout << ". ";
        }
        else {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void PrintNextBirthday (std::map<std::time_t, std::vector<std::string>>& list) {
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentLocal = std::localtime(&currentTime);

    std::map<std::time_t, std::vector<std::string>>::iterator searchedPosition;
    std::time_t temp = 0;

    for (auto & i : list) {
        std::tm* local = std::localtime(&i.first);
        if (local->tm_mon == currentLocal->tm_mon && local->tm_mday == currentLocal->tm_mday) {
            std::cout << "Today is the birthday of ";
            PrintNames( i.second);
        }
        else if (local->tm_mon > currentLocal->tm_mon ||
                (local->tm_mon == currentLocal->tm_mon && local->tm_mday > currentLocal->tm_mday)) {

        }

        std::cout << std::put_time(local, "%m/%d") << ": ";

        for (auto & j : i.second) {
            std::cout << j  << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::map<std::time_t, std::vector<std::string>> listOfBirthdays;

    Input( listOfBirthdays);


//    for (auto & i : listOfBirthdays) {
//        std::tm* local = std::localtime(&i.first);
//        std::cout << std::put_time(local, "%Y/%m/%d") << ": ";
//        for (auto & j : i.second) {
//            std::cout << j  << " ";
//        }
//        std::cout << std::endl;
//    }

//    std::string inputName;
//    std::string inputDate;
//
//    std::cout << "Enter \"end\" to complete the entry." << std::endl;
//    std::cout << "Enter your friend's name and date of birth in yyyy/mm/dd format." << std::endl;
//    do {
//        Input( inputName, inputDate);
//
//
//
//        std::cout << inputDate << " - " << inputName << std::endl;
//    }
//    while (inputName != "end");

//    std::time_t time = std::time(nullptr);
//    std::cout << "1 -> " << time << std::endl;
//    std::tm* local = std::localtime(&time);
//
//    std::cout << "2 -> " << std::asctime(local) << std::endl;
//    std::cout << "2 -> " << local->tm_sec << std::endl;
//    std::cout << "2 -> " << local->tm_min << std::endl;
//    std::cout << "2 -> " << local->tm_hour << std::endl;
//    std::cout << "2 -> " << local->tm_mday << std::endl;
//    std::cout << "2 -> " << local->tm_mon << std::endl;
//    std::cout << "2 -> " << local->tm_year << std::endl;
//
//    std::cin >> std::get_time(local, "%H:%M");
//    std::cout << "3 -> " << time << std::endl;
//    std::cout << "3 -> " << std::asctime(local) << std::endl;
//
//    std::time_t time2 = std::mktime(local);
//    std::cout << "4 -> " << time2 << std::endl;
//
//    std::tm* local2 = std::localtime(&time2);
//    std::cout << "4 -> " << std::asctime(local2) << std::endl;

    return 0;
}
