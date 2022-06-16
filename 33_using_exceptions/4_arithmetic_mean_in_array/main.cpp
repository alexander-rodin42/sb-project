#include <iostream>
#include <vector>

template < typename T >
T getAverage(T* begin, T* end) {
    T result = 0;
    int elementCount = 0;
    for (auto i = begin; i != end; ++i) {
        result += *i;
        ++elementCount;
    }

    return result/elementCount;
}

template < typename T >
void input(T* begin, T* end)
{
    std::cout << "Fill the array:" << std::endl;
    for (auto i = begin; i != end; ++i) {
        std:: cout << i - begin << " - ";
        std::cin >> *i;
    }
}

int main() {
    int array1[10];
    input(std::begin(array1), std::end(array1));
    std::cout << getAverage(std::begin(array1), std::end(array1)) << std::endl;

    double array2[10];
    input(std::begin(array2), std::end(array2));
    std::cout << getAverage(std::begin(array2), std::end(array2)) << std::endl;

    return 0;
}
