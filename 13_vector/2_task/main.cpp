#include <iostream>
#include <vector>

float PurchasesAmount (const std::vector<float>& goodsCost, const std::vector<int>& purchaseIndex) {
    float result = 0.0;

    for (int index : purchaseIndex) {
        result += goodsCost[index];
    }
    return result;
}

int main() {
    std::vector<float> goodsCost {2.5, 4.25, 3.0, 10.0};
    std::vector<int> purchaseIndex {1, 1, 0, 3};

    std::cout << "The total cost will be equal to ";
    std::cout << PurchasesAmount( goodsCost, purchaseIndex) << "." << std::endl;
    return 0;
}
