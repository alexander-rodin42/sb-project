#include <iostream>
#include <thread>
#include <mutex>
#include <ctime>
#include <vector>
#include <map>
#include <string>

enum Dish {
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI
};

std::map<int, int> readyOrders;
bool exitProgram = false;

std::mutex exit_access;
std::mutex print_access;
std::mutex kitchen_access;
std::mutex ready_orders_access;


void print(const std::string& message) {
    print_access.lock();
    std::cout << message << std::endl;
    print_access.unlock();
}

void input_exit(bool* exit) {
    char input;
    do {
        std::cin >> input;
    }
    while (input != '0');

    exit_access.lock();
    *exit = true;
    exit_access.unlock();
}

bool check_exit() {
    exit_access.lock();
    bool result = exitProgram;
    exit_access.unlock();
    return result;
}

std::string dish_to_string(const int& dish) {
    if (dish == PIZZA) {
        return "Pizza";
    }
    else if (dish == SOUP) {
        return "Soup";
    }
    else if (dish == STEAK) {
        return "Steak";
    }
    else if (dish == SALAD) {
        return "Salad";
    }
    else if (dish == SUSHI) {
        return "Sushi";
    }
    else {
        return "None";
    }
}

void cook_dish(const int& orderNumber, const int& dish) {
    print("Order #" + std::to_string(orderNumber) + " received for " + dish_to_string(dish));

    kitchen_access.lock();
    print("Started making " + dish_to_string(dish));

    std::srand(std::time(nullptr));
    int cookingTime = 5 + rand() % 11;
    std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
    print(dish_to_string(dish) + " is ready!" + " (#" + std::to_string(orderNumber) +
          ", " + std::to_string(cookingTime) + ")");
    kitchen_access.unlock();

    ready_orders_access.lock();
    readyOrders[orderNumber] = dish;
    ready_orders_access.unlock();
}

bool check_ready_orders() {
    ready_orders_access.lock();
    bool result = !readyOrders.empty();
    ready_orders_access.unlock();
    return result;
}

void delivery_orders() {
    do {
        if (check_ready_orders()) {
            ready_orders_access.lock();
            do {
                auto first = readyOrders.begin();
                print("Order #" + std::to_string(first->first) + " - the " + dish_to_string(first->second) + " has been delivered");
                readyOrders.erase(first);
            } while (!readyOrders.empty());
            ready_orders_access.unlock();

            std::this_thread::sleep_for(std::chrono::seconds(30));
        }
        else {
            print("The courier is waiting for ready orders.");
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    } while (!(check_exit() && readyOrders.empty()));
}

int main() {
    std::srand(std::time(nullptr));
    int orderNumber = 0;
    std::cout << "Enter \"0\" to stop orders coming in." << std::endl;

    std::thread courier(delivery_orders);
    std::thread exit(input_exit, &exitProgram);

    while (!check_exit()) {
        std::thread order(cook_dish, ++orderNumber, rand() % 5);
        order.detach();

        std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 6));
    }

    kitchen_access.lock();
    exit.join();
    courier.join();
    kitchen_access.unlock();

    return 0;
}