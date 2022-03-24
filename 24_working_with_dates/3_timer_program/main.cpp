/*
    Задание 3. Реализация программы таймера

    Реализуйте работу точного таймера с визуальной отдачей.

    В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на таймере, и нажимает
«Ввод».
    После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно сообщается пользователю.
Формат вывода такой же, как и при вводе интервала: минуты и секунды.
    Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль специального сообщения.
Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!

    Советы и рекомендации
    Для ввода значения для засекания времени используйте std::get_time, но в качестве формата запросите только минуты и
секунды. Целевое время для остановки таймера вычислите сами с помощью манипуляции над текущим std::time. Количество
оставшегося времени выводите в цикле и вычислите его самостоятельно с помощью обращения с типом std::time_t как с
секундами.
*/

#include <iostream>
#include <ctime>
#include <iomanip>

void FirstTimer () {
    std::time_t timer = 0;
    std::tm* local = localtime(&timer);
    std::cout << "Enter time in the format (mm:ss): ";
    std::cin >> std::get_time(local, "%M:%S");

    timer = int(std::mktime(local));
    std::time_t lagTime = std::time(nullptr);

    while (timer >= 0) {
        std::time_t currentTime = std::time(nullptr);
        if (currentTime > lagTime) {
            std::tm* timeLeft = localtime(&timer);
            std::cout << std::put_time(timeLeft, "%M:%S") << std::endl;
            timer -= currentTime - lagTime;
            lagTime = currentTime;
        }
    }
    std::cout <<"DING! DING! DING!" << std::endl;
}

void SecondTimer () {
    std::time_t timer = 0;
    std::tm* local = localtime(&timer);
    std::cout << "Enter time in the format (mm:ss): ";
    std::cin >> std::get_time(local, "%M:%S");

    timer = int(std::mktime(local));
    std::time_t currentTime = std::time(nullptr);
    std::time_t lagTime = currentTime;
    std::time_t stopTime = currentTime + timer;

    while (currentTime <= stopTime) {
        currentTime = std::time(nullptr);
        if (currentTime > lagTime) {
            std::tm* timeLeft = localtime(&timer);
            std::cout << std::put_time(timeLeft, "%M:%S") << std::endl;
            timer -= currentTime - lagTime;
            lagTime = currentTime;
        }
    }
    std::cout <<"DING! DING! DING!" << std::endl;
}

int main() {
    FirstTimer();
    SecondTimer();
    return 0;
}
