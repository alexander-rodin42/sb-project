#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::cout << "(1.1)--------------------" << std::endl;
    std::cout << std::time(nullptr) << std::endl;

    std::cout << "(1.2)--------------------" << std::endl;
    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t); // pointer
    std::cout << local->tm_hour << std::endl;      // hour
    std::cout << std::asctime(local) << std::endl; // Fri Mar 18 13:18:05 2022

    std::cout << "(2.1)----Output-dates----" << std::endl;
    // #include <iomanip>  <-- to output the required format
    std::cout << std::put_time(local, "%Y") << std::endl; //year - %Y (4 characters)
    std::cout << std::put_time(local, "%y") << std::endl; //year - %y (2 characters)
    std::cout << std::put_time(local, "%Y/%m/%d") << std::endl; // month - %m, day - %d
    std::cout << std::put_time(local, "%B") << std::endl;       // month - %B
    std::cout << std::put_time(local, "%Y/%m/%d %H:%M:%S") << std::endl; // hour - %H (24), minutes -%M, seconds - %S
    std::cout << std::put_time(local, "%Y/%m/%d %I:%M:%S") << std::endl; // hour - %I (12)
    std::cout << std::put_time(local, "%A") << std::endl; // day of the week - %A

    std::cout << "(3.1)----Input-dates-----" << std::endl;
    // #include <iomanip>  <-- to enter dates
    std::time_t t2 = std::time(nullptr);
    std::tm local2 = *std::localtime(&t2);
    std::cin >> std::get_time(&local2, "%H:%M");
    std::cout << std::asctime(&local2) << std::endl;

    std::cout << "(4.1)-Date-manipulation--" << std::endl;
    std::time_t start = std::time(nullptr);
    std::tm* localStart = std::localtime(&start);
    std::cout << "Start - " << asctime(localStart);

    int delay;
    std::cin >> delay;

    std::time_t finish = std::time(nullptr);
    std::tm* localFinish = std::localtime(&finish);
    std::cout << "Finish - " << asctime(localFinish);

    double difference = std::difftime(finish, start); // #include <ctime>
    std::cout << "Difference = " << difference << std::endl;

    std::time_t future = finish + (std::time_t)difference;
    std::tm* localFuture = std::localtime(&future);
    std::cout << "Future - " << asctime(localFuture);

    // You don't need to do so:
//    std::cout << "(4.2)-Date-manipulation--" << std::endl;
//    localFuture->tm_sec += 12; // 50 seconds += 12 = runtime error!!!!!!
//    std::cout << "Future - " << asctime(localFuture);

    std::cout << "(5.1)--cpp-reference--" << std::endl;

    std::time_t t3 = std::time(nullptr);
    std::tm tm3 = *std::localtime(&t3);
    std::cout.imbue(std::locale("ru_RU.utf8"));
    std::cout << "ru_RU: " << std::put_time(&tm3, "%c %Z") << '\n';
    std::cout.imbue(std::locale("ja_JP.utf8"));
    std::cout << "ja_JP: " << std::put_time(&tm3, "%c %Z") << '\n';
    // UTC
    std::cout << "(5.2)--cpp-reference--" << std::endl;
    std::time_t t4 = std::time(nullptr);
    std::tm tm4 = *std::gmtime(&t4);
    std::cout << std::asctime(&tm4) << std::endl;

    return 0;
}
