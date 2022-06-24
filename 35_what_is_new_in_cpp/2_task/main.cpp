#include <iostream>
#include <memory>
#include <vector>
#include <unordered_set>


auto getNoRepeats = [](const std::vector<int>& values) {
    auto result = std::make_unique<std::vector<int>>();
    if (values.empty()) {
        return result;
    }
    std::unordered_set<int>  list;
    list.insert(values.begin(), values.end());

    for (auto& i : list) {
        int count = 0;
        for (auto& j : values) {
            if (i == j) {
                ++count;
            }
        }
        if (count == 1) {
            result->push_back(i);
        }
    }
    return result;
};

int main() {
    std::vector<int> values = {1, 3, 5, 4, 6, 3, 2, 9, 5, 7};
    auto uniqueVector = getNoRepeats(values);

    for(auto& i : *uniqueVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
