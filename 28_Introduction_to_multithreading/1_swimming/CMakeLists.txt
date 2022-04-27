cmake_minimum_required(VERSION 3.20)
project(1_swimming)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_swimming src/main.cpp
        include/Swimmer.h src/Swimmer.cpp
        include/Verification.h src/Verification.cpp)

target_include_directories(1_swimming PUBLIC include)
