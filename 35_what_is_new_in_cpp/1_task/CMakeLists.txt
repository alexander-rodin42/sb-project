cmake_minimum_required(VERSION 3.20)
project(1_task)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_task src/main.cpp
        src/MyClass.cpp include/MyClass.h)

target_include_directories(1_task PUBLIC include)
