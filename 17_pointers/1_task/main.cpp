#include <iostream>

void Swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;

    int b = 20;

    Swap(&a, &b);

    std::cout << a << " " << b;

    return 0;
}
