cmake_minimum_required(VERSION 3.20)
project(1_shopping_cart_operation)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_shopping_cart_operation src/main.cpp
        src/Basket.cpp include/Basket.h)

target_include_directories(1_shopping_cart_operation PUBLIC include)