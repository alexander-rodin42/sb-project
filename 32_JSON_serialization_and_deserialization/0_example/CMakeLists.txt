cmake_minimum_required(VERSION 3.20)
project(0_example)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(0_example main.cpp)

target_link_libraries(0_example PRIVATE nlohmann_json::nlohmann_json)