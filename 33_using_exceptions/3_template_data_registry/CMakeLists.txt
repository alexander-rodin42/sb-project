cmake_minimum_required(VERSION 3.20)
project(3_template_data_registry)

set(CMAKE_CXX_STANDARD 14)

add_executable(3_template_data_registry src/main.cpp
        src/Registry.cpp include/Registry.h)

target_include_directories(3_template_data_registry PUBLIC include)
