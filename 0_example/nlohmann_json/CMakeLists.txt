cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME example)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

include(FetchContent)
FetchContent_Declare(
        json
        URL
        https://github.com/nlohmann/json/releases/download/v3.11.1/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
