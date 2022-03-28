cmake_minimum_required(VERSION 3.20)
project(1_operations_simulator VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(1_operations_simulator src/main.cpp ${MY_INCLUDE_DIR}/point.h src/point.cpp
                                                   ${MY_INCLUDE_DIR}/incision.h src/incision.cpp)

target_include_directories(1_operations_simulator PUBLIC ${MY_INCLUDE_DIR})

