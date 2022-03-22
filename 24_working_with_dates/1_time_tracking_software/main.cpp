/*
     * Задание 1. Реализация программы учёта времени

    Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.

    Пользователь взаимодействует с программой с помощью команд:

    Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название
задачи, над которой он планирует сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна быть
автоматически завершена и начата новая.
    Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
    Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено.
Также выводится название текущей выполняемой задачи, если таковая имеется.
    Команда exit выходит из программы.


Советы и рекомендации

Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

struct Task {
    std::string taskName{};
    std::time_t begin{};
    std::time_t end{};
    double elapseTime = 0.0;
};

void InputCommand (std::string& command) {
    do {
        std::cout << "Enter command: ";
        std::cin >> command;
    }
    while (command != "begin" && command != "end" && command != "status" && command != "exit");
}

void CompleteTheLastTask (std::vector<Task>& taskList, std::time_t& currentTime) {
    if (!taskList.empty() && taskList.back().elapseTime == 0.0) {
        taskList.back().end = currentTime;
        taskList.back().elapseTime = std::difftime(taskList.back().end, taskList.back().begin);
    }
}

void Begin (std::vector<Task>& taskList, std::string& taskName) {
    std::time_t currentTime = std::time(nullptr);

    std::cout << "Enter a new task: ";
    std::cin >> taskName;

    CompleteTheLastTask( taskList, currentTime);

    taskList.emplace_back();
    taskList.back().taskName = taskName;
    taskList.back().begin = currentTime;
}

void End (std::vector<Task>& taskList) {
    std::time_t currentTime = std::time(nullptr);

    CompleteTheLastTask( taskList, currentTime);
}

void Status (std::vector<Task>& taskList) {
    std::cout << "-------------------------------"  << std::endl;
    std::cout << "Begin    End      Emp.time Task"  << std::endl;

    if (!taskList.empty()) {
        for (auto & i : taskList) {
            std::tm* local = std::localtime(&i.begin);
            std::cout << std::put_time(local, "%H:%M:%S") << " ";

            if (i.elapseTime != 0.0) {
                local = std::localtime(&i.end);
                std::cout << std::put_time(local, "%H:%M:%S") << " ";

                auto elapseTime = (std::time_t)(i.elapseTime);
                local = std::gmtime(&elapseTime);
                std::cout << std::put_time(local, "%H:%M:%S") << " ";

                std::cout << i.taskName << std::endl;
            } else {
                std::cout<< "in work           "  << i.taskName << std::endl;
            }
        }
    }
    else {
        std::cout << "Task list is empty" << std::endl;
    }
}

int main() {
    std::string userInput;
    std::vector<Task> taskLList;

    do {
        InputCommand(userInput);

        if (userInput == "begin") {
            Begin( taskLList, userInput);
        }
        else if (userInput == "end") {
            End( taskLList);
        }
        else if (userInput == "status") {
            Status( taskLList);
        }
    }
    while (userInput != "exit");

    return 0;
}