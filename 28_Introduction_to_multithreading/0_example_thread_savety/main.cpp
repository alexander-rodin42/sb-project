#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::string> history;
std::mutex history_access; // #include <mutex>

void wait_for_call(int time, std::string name) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "Id: " << std::this_thread::get_id() << std::endl;
    std::cout << "RING (COURIER) - " << name << std::endl;

    history_access.lock(); // <---
    history.push_back(name);
    history_access.unlock(); // --->
}

int main() {
    int time;
    std::cin >> time;
    std::string name;
    std::cin >> name;
    std::cout << "Id: " << std::this_thread::get_id() << std::endl;

    std::thread call(wait_for_call, time, name);
    std::thread call2(wait_for_call, 4, "SkillBox");

    call.join();
    call2.join();

    history_access.lock();
    std::cout << "Missed calls:" << std::endl;
    for (auto & i : history) {
        std::cout << i << std::endl;
    }
    history_access.unlock();

    return 0;
}
