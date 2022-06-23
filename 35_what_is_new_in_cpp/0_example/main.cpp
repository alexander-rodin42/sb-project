#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>

class Part {
public:
    Part(const int& inValue)
        : value(inValue) {}
private:
    int value{};
};

class Tool {
public:
    Tool(std::initializer_list<Part> inPart) {
        mParts = inPart;
    }
private:
    std::vector<Part> mParts;
};

auto averageAndExtremum = [](std::vector<int> temperatures, int& avg, int& min, int& max) {
    if (temperatures.empty()) {
        return ;
    }
    else {
        max = min = avg = temperatures.front();
        auto sum = 0;

        for (auto& i : temperatures) {
            ++sum;

            if (i > max)
                max = i;
            else if (i < min)
                min = i;
        }
        avg = sum / temperatures.size();
    }
};

auto averageAndExtremum2 = [](std::vector<int> temperatures) {
    if (temperatures.empty()) {
        return std::tuple<int, int, int>{};
    }

    int min, max, avg;
    max = min = avg = temperatures.front();
    auto sum = 0;

    for (auto& i : temperatures) {
        sum += i;

        if (i > max)
            max = i;
        else if (i < min)
            min = i;
    }
    avg = sum / temperatures.size();

    return std::tuple<int, int, int>{avg, min, max};
};

int main() {
    // for (int & i : array)
    // auto i = 5;

    //initialization list:
    int x{};
    int y{5};
    int z[] = {1, 2, 3};
    std::initializer_list<int> i = {1, 2, 3};
    std::vector<int> j = {1, 2, 3};

    // custom class initialization list:
    Tool t = {1, Part(5)};

    // lambda expression or lambda function:
    // []()

    //std::sort(units.begin(), units.end(), [](Unit& unit1, Unit& unit2)
    // {
    //     return unit1.height() < unit2.height();
    // }
    // );

    //--Data Structures:

    //#include <array>
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    //#include <tuple>
    std::vector<int> values = {1, 23, -2, 15, 21, 10, 36};
    auto result = averageAndExtremum2(values);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << std::endl;

    //#include <unordered_map>
    std::unordered_map<std::string, int> m;

    //#include <unordered_set>
    std::unordered_set<std::string> s = {"first", "second", "third"};
    if (s.count("ssdfsdf")) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //smart pointer
    // auto u1 = std::make_unique<Unit>();
    // auto u2 = std::make_shared<Unit>();

    //#include <filesystem> cpp - 17
    //std::filesystem::path p("/home/user/file.txt")
    //auto fileEnd = p.end;
    //std::filesystem::exists(p);

    return 0;
}
