#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <thread>


void wait_for_call(int time, std::string name) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "Id: " << std::this_thread::get_id() << std::endl;
    std::cout << "RING (COURIER) - " << name << std::endl;
}

int main() {
    // #include <thread>
    int time;
    std::cin >> time;
    std::string name;
    std::cin >> name;
    std::cout << "Id: " << std::this_thread::get_id() << std::endl;

    std::thread call(wait_for_call, time, name);
    std::thread call2(wait_for_call, 4, "SkillBox");

    call.detach(); // отвязать поток от call
    call2.detach(); // отвязать поток от call2

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "CALL (FRIEND)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));

    if (call.joinable()) call.join(); // Проверить связал ли поток call, если да то присоедениеть.
    if (call2.joinable()) call2.join();

    return 0;
}
