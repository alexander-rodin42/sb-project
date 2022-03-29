cmake_minimum_required(VERSION 3.20)
project(2_computer_simulator VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(2_computer_simulator src/main.cpp
        ${INCLUDE_DIR}/cpu.h src/cpu.cpp
        ${INCLUDE_DIR}/ram.h src/ram.cpp
        ${INCLUDE_DIR}/disk.h src/disk.cpp
        ${INCLUDE_DIR}/gpu.h src/gpu.cpp
        ${INCLUDE_DIR}/kbd.h src/kbd.cpp)

target_include_directories(2_computer_simulator PUBLIC ${INCLUDE_DIR})