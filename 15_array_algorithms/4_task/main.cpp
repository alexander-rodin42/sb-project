#include <iostream>
#include <cmath>

void PrintArray (const int (&numbers)[6]) {
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

void SortArrayAbs (int (&numbers)[6]) {
    for (int i = 6; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if ( abs( numbers[j]) > abs( numbers[j + 1])) { // (numbers[j] * numbers[j] > numbers[j + 1] * numbers[j + 1])
                int temp = numbers[j];                      // pow( numbers[j]) > pow( numbers[j + 1])
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numbers[6] = {-100,-50, -5, 1, 10, 15};

    SortArrayAbs( numbers);
    PrintArray( numbers);

    return 0;
}
