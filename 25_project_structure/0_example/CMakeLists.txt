cmake_minimum_required(VERSION 3.20)
project(0_example VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(0_example src/main.cpp include/my-math.h src/my-math.cpp)
target_include_directories(0_example PUBLIC include)