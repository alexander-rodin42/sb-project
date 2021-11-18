#include <iostream>

int main() {
    float userNumbers[15];

    std::cout << "Enter 15 floating point numbers:" << std::endl;
    for (int i = 0; i < 15; i++) {
        std::cout << i << " - ";
        std::cin >> userNumbers[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = i + 1; j < 15; j++) {
            if (userNumbers[j] < userNumbers[i]) {
                float minimumNumber = userNumbers[j];
                userNumbers[j] = userNumbers[i];
                userNumbers[i] = minimumNumber;
            }
        }
    }

//    float minimumNumber;
//    int minimumIndex;
//
//    for (int i = 0; i < 14; i++) {
//        minimumNumber = userNumbers[i];
//        minimumIndex = i;
//        for (int j = i + 1; j < 15; j++) {
//            if (userNumbers[j] < minimumNumber) {
//                minimumNumber = userNumbers[j];
//                minimumIndex = j;
//            }
//        }
//
//        for (int j = minimumIndex; j > i; j--) {
//            userNumbers[j] = userNumbers[j - 1];
//        }
//        userNumbers[i] = minimumNumber;
//    }

    for (float i : userNumbers) {
        std::cout << i << " ";
    }

    return 0;
}
