#include <iostream>

//void Swap (int (&array)[10]) {
//    for (int i = 0; i < 5; i ++) {
//        int temp = array[i];
//        array[i] = array[9 - i];
//        array[9 - i] = temp;
//    }
//}

void Swap (int *begin, int *end) {
    int j = 1;

    for (int *i = begin; i != end - ((end - begin) / 2); i++) {
        int temp = *i;
        *i = *(end - j);
        *(end - j) = temp;
        j++;
    }
}

int main() {
    int array[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    Swap( std::begin(array), std::end(array));
//    Swap( array);

    for (int i : array) {
        std::cout << i << " ";
    }

    return 0;
}
