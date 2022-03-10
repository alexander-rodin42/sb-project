#include <iostream>
#include <string>
#include <map>


bool CheckInput (const std::string& input) {
    for (auto i : input) {
        if (!(i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z')) {
            return false;
        }
    }
    return true;
}

void ConvertCommandToFormat (std::string& name) {
    for (int i = 0; i < name.length(); i++){
        if (i == 0 && name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 32;
        }
        else if (i != 0 && name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        }
    }
}

void UserInput(std::string& input) {
    do {
        std::cout << "Enter last name or command: ";
        std::cin >> input;
    } while (!CheckInput( input));

    ConvertCommandToFormat(input);
}

void AddToQueue (const std::string& input, std::map<std::string, int>& queue) {
    ++queue[input];
}

void CallThePerson (std::map<std::string, int>& queue) {
    if (queue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    }
    else {
        auto firstInLine = queue.begin();

        std::cout << firstInLine->first << ", please go to the reception." <<  std::endl;
        firstInLine->second--;

        if (firstInLine->second <= 0) {
            queue.erase( firstInLine);
        }
    }
}

void RunCommand (const std::string& command, std::map<std::string, int>& queue) {
    if (command == "Exit") {
        std::cout << "Thank you for visiting us, have a nice day!" << std::endl;
    }
    else if (command == "Next") {
        CallThePerson( queue);
    }
    else {
        AddToQueue( command, queue);
    }
}

int main() {
    std::map<std::string, int> queue;
    std::string input;

    std::cout << "Possible commands:" << std::endl;
    std::cout << "Enter \"Exit\" to exit." << std::endl;
    std::cout << "Enter \"Next\" to call the person to the registry." << std::endl;
    do {
        UserInput( input);
        RunCommand( input, queue);
    } while ( input != "Exit");

    return 0;
}

/*
    Задание 2. Регистратура

    Напишите программу «Регистратура».

    На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди становятся в очередь, а по запросу Next
необходимо вызвать в регистратуру человека с фамилией, идущей первой в лексикографическом порядке (по алфавиту), и
вывести его фамилию на экран. Фамилии пациентов могут повторяться.

    Каждый запрос (на добавление и вывод) должен работать за O(logn).
    Пример:
← Sidorov
← Ivanov
← Ivanov
← Petrov
← Next
→ Ivanov
← Next
→ Ivanov
← Next
→ Petrov

    Чек-лист для проверки задачи
    Программа корректно выводит фамилии в лексикографическом порядке.
    Программа использует только заголовочные файлы <iostream>, <string>, <map>.
 */
