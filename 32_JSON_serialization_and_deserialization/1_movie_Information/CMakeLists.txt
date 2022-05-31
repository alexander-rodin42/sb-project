cmake_minimum_required(VERSION 3.20)
project(1_movie_Information)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(1_movie_Information main.cpp)

target_link_libraries(1_movie_Information PRIVATE nlohmann_json::nlohmann_json)