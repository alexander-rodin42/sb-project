cmake_minimum_required(VERSION 3.20)
project(2_fishing_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_fishing_game src/main.cpp
        src/Pond.cpp include/Pond.h
        src/CustomExceptions.cpp include/CustomExceptions.h)

target_include_directories(2_fishing_game PUBLIC include)