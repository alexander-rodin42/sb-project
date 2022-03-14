#include <iostream>

#define MESSAGE "Enter the number of the day of the week: "

#define MONDAY    "Monday"
#define TUESDAY   "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY  "Thursday"
#define FRIDAY    "Friday"
#define SATURDAY  "Saturday"
#define SUNDAY    "Sunday"


int main() {
    int userInput;
    do {
        std::cout << MESSAGE;
        std::cin >> userInput;
    } while (userInput < 1 || userInput > 7);

    if (userInput == 1) {
        std::cout << MONDAY << std::endl;
    }
    else if (userInput == 2) {
        std::cout << TUESDAY << std::endl;
    }
    else if (userInput == 3) {
        std::cout << WEDNESDAY << std::endl;
    }
    else if (userInput == 4) {
        std::cout << THURSDAY << std::endl;
    }
    else if (userInput == 5) {
        std::cout << FRIDAY << std::endl;
    }
    else if (userInput == 6) {
        std::cout << SATURDAY << std::endl;
    }
    else {
        std::cout << SUNDAY << std::endl;
    }

    return 0;
}

/*
    Задание 1. Реализация продвинутый ввод и вывод дней недели

    Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели в текстовом виде в
консоль.

    В начале программы пользователь вводит день недели в виде его порядкового номера. В результате в консоли появляется
буквенное отображение этого дня недели.

    В этом упражнении запрещается использовать классические переменные, кроме как для хранения ввода пользователя.
Использовать строковые литералы напрямую тоже нельзя. Всё должно быть реализовано исключительно на макросах.

    Советы и рекомендации

    Конкатенация двух фрагментов может породить токен, который в свою очередь является именем макроса, и этот макрос
тоже раскроется. Используйте данное свойство для перевода константы дня недели в строковый литерал.

Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.
*/
