cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME search_engine)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

include(FetchContent)
FetchContent_Declare(
        json
        URL
        https://github.com/nlohmann/json/releases/download/v3.11.1/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(${PROJECT_NAME} src/main.cpp
        src/ConverterJSON.cpp include/ConverterJSON.h
        src/InvertedIndex.cpp include/InvertedIndex.h
        src/SearchServer.cpp  include/SearchServer.h
        src/CustomExceptions.cpp include/CustomExceptions.h
        src/WordHandler.cpp include/WordHandler.h
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(unit_tests)
