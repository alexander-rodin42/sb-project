cmake_minimum_required(VERSION 3.20)
project(1_smart_toy_pointer)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_smart_toy_pointer src/main.cpp
        src/Dog.cpp include/Dog.h
        src/Toy.cpp include/Toy.h
        src/SmartPtrToy.cpp include/SmartPtrToy.h
        src/SharedPtrToy.cpp include/SharedPtrToy.h)

target_include_directories(1_smart_toy_pointer PUBLIC include)