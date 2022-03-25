#include <iostream>
#include "my-math.h"
#include "my-math.h" //Add "#pragma once" in header file

int main() {
    int temp;
    std::cout << circumference( 3.5) << std::endl;
    std::cin >> temp;
    return 0;
}

/*
CMakeLists:

add_executable(0_example src/main.cpp include/my-math.h src/my-math.cpp)
target_include_directories(0_example PUBLIC include)

root folder:
${CMAKE_SOURCE_DIR}
*/