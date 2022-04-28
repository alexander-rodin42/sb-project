cmake_minimum_required(VERSION 3.20)
project(2_simulation_of_the_station)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_simulation_of_the_station src/main.cpp
        include/Train.h src/Train.cpp)

target_include_directories(2_simulation_of_the_station PUBLIC include)
