cmake_minimum_required(VERSION 3.20)
project(2_movie_data_analysis)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(2_movie_data_analysis main.cpp)

target_link_libraries(2_movie_data_analysis PRIVATE nlohmann_json::nlohmann_json)
