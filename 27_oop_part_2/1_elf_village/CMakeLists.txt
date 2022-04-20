cmake_minimum_required(VERSION 3.20)
project(1_elf_village)

set(CMAKE_CXX_STANDARD 14)

add_executable(1_elf_village src/main.cpp
        include/Branch.h src/Branch.cpp
        include/Verification.h src/Verification.cpp
        include/Forest.h src/Forest.cpp)

target_include_directories(1_elf_village PUBLIC include)