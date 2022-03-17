#include <iostream>

#define SPRING 0
#define SUMMER 1
#define AUTUMN 2
#define WINTER 3

int main() {
    int timeOfYear = SPRING

#if timeOfYear == SPRING
    std::cout << "Spring" << std::endl;
#endif

#if timeOfYear == SUMMER
    std::cout << "Summer" << std::endl;
#endif

#if timeOfYear == AUTUMN
    std::cout << "Autumn" << std::endl;
#endif

#if timeOfYear == WINTER
    std::cout << "Winter" << std::endl;
#endif
    return 0;
}


/*
    Задание 3. Вывод времени года

    Используя макросы вместе с условными директивами прекомпиляции (#if / #endif), реализуйте простую программу по
выводу названия времени года в консоль.

    Пользователь программы в данном случае сам программист. С помощью определения одного из макросов: SPRING, SUMMER,
AUTUMN или WINTER, он задаёт сезон, название которого хочет увидеть на экране. При компиляции и запуске программы на
экране должно появиться название именно этого сезона и только его.

    Советы и рекомендации

    Так как препроцессор работает вообще до компиляции, то в #if / #endif директивы вы можете обернуть всю функцию
main сразу.

    Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.
*/