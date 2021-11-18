#include <iostream>

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int beginningMultitude = numbers[0];
    int sumNumbers = 0;

    for (int i : numbers) {
        sumNumbers += i;
        if (beginningMultitude > i) {
            beginningMultitude = i;
        }
    }
    if (sumNumbers == beginningMultitude * 15 + 105) {
        std::cout << "No repetitions." << std::endl;
    } else {
        std::cout << sumNumbers - beginningMultitude * 14 - 91 << std::endl;
    }

//    for (int i = 0; i < 14; i++) {
//        for (int j = i + 1; j < 15; j++) {
//            if (numbers[i] == numbers[j]) {
//                std::cout << numbers[i] << std::endl;
//                //std::cout << i << " - " << j << std::endl;
//            }
//        }
//    }
    return 0;
}
