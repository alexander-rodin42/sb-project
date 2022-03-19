#include <iostream>

#define WAGONS_NUMBER 10
#define MAX_PASSENGERS 20
#define REPEAT(func, iterator) for (;iterator < WAGONS_NUMBER; func)

void Input (int& sum, int& input, int& wagonsNumber) {
    std::cout << "Enter the number of passengers for car No." << wagonsNumber + 1 << ": ";
    std::cin >> input;
    sum += input;
    ++wagonsNumber;
}

void FindCrowdedWagon (const int& passengers, const int& max, int& wagonsNumber) {
    if (passengers > max) {
        std::cout << "Car No." << wagonsNumber + 1 << " is crowded!" << std::endl;
    }
    ++wagonsNumber;
}

void FindEmptySeatsWagon (const int& passengers, const int& max, int& wagonsNumber) {
    if (passengers < max) {
        std::cout << "There are empty seats in carriage No." << wagonsNumber + 1 << "!" << std::endl;
    }
    ++wagonsNumber;
}


int main() {
    int wagons[WAGONS_NUMBER];
    int iterator = 0;
    int sum = 0;

    REPEAT(Input(sum, wagons[iterator], iterator), iterator);
    iterator = 0;
    REPEAT(FindCrowdedWagon(wagons[iterator], MAX_PASSENGERS, iterator), iterator);
    iterator = 0;
    REPEAT(FindEmptySeatsWagon(wagons[iterator], MAX_PASSENGERS, iterator), iterator);

    std::cout << "Total number of passengers in all carriages: " << sum << std::endl;
    return 0;
}

/*
Задание 2. Анализ заполненности вагонов в поезде

    В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20-ти пассажиров — это оптимальное их
количество. Проанализируйте количество людей в каждом из вагонов и сначала сообщите об излишне заполненных вагонах,
далее о вагонах с пустыми пассажирскими местами. В заключении выведите общее количество пассажиров во всех вагонах.

    При старте программы пользователь вводит количество пассажиров в каждом из вагонов. Замечания о вагонах должны
выводиться в стандартную консоль.

    При выполнении задания пользоваться for-циклами напрямую не разрешается, только опосредованно, через макросы.

    Советы и рекомендации

    С помощью макроса реализуйте модульный способ вызова функции-предиката над элементами массива. Сами
функции-предикаты реализуйте отдельно, в виде обычных классических функций (не макросов).

    Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.
*/