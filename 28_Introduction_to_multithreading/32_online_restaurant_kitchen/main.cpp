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

std::map<int, int> orders;
std::map<int, int> readyOrders;
int deliveredOrders = 0;

std::mutex delivered_orders_access;
std::mutex orders_access;
std::mutex ready_orders_access;
std::mutex print_access;

void print(const std::string& message) {
    print_access.lock();
    std::cout << message << std::endl;
    print_access.unlock();
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

bool check_delivered_orders_max() {
    delivered_orders_access.lock();
    bool result = deliveredOrders >= 10;
    delivered_orders_access.unlock();
    return result;
}

bool check_orders() {
    orders_access.lock();
    bool result = !orders.empty();
    orders_access.unlock();
    return result;
}

bool check_ready_orders() {
    ready_orders_access.lock();
    bool result = !readyOrders.empty();
    ready_orders_access.unlock();
    return result;
}

void start_orders() {
    std::srand(std::time(nullptr));

    for (int i = 0; i < 10; ++i) {
        int dish = rand() % 5;
        print("(!) Order #" + std::to_string(i + 1) + " received for " + dish_to_string(dish));

        orders_access.lock();
        orders[i + 1] = dish;
        orders_access.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 6));
    }
}

void cook() {
    std::srand(std::time(nullptr));

    while (!check_delivered_orders_max()) {
        if (check_orders()) {
            orders_access.lock();
            auto first = orders.begin();
            print("(>) Started making " + dish_to_string(first->second));
            orders_access.unlock();

            int cookingTime = 5 + rand() % 11;
            std::this_thread::sleep_for(std::chrono::seconds(cookingTime));

            orders_access.lock();
            print("(>) " + dish_to_string(first->second) + " is ready!" + " (#" + std::to_string(first->first) +
                  ", " + std::to_string(cookingTime) + " sec.)");

            ready_orders_access.lock();
            readyOrders[first->first] = first->second;
            ready_orders_access.unlock();

            orders.erase(first);
            orders_access.unlock();
        }
        else {
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }
}

void delivery_orders() {
    do {
        if (check_ready_orders()) {
            ready_orders_access.lock();
            do {
                auto first = readyOrders.begin();
                print("(v) Order #" + std::to_string(first->first) + " - the " + dish_to_string(first->second) + " has been delivered");
                readyOrders.erase(first);

                delivered_orders_access.lock();
                ++deliveredOrders;
                delivered_orders_access.unlock();

            } while (!readyOrders.empty());
            ready_orders_access.unlock();

            if (!check_delivered_orders_max()) {
                std::this_thread::sleep_for(std::chrono::seconds(30));
            }
        }
        else {
            print("The courier is waiting for ready orders.");
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    } while (!check_delivered_orders_max());
}

int main() {
    std::thread order (start_orders);
    order.detach();

    std::thread kitchen (cook);
    kitchen.detach();

    std::thread delivery (delivery_orders);
    delivery.join();

    return 0;
}
