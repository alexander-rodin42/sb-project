cmake_minimum_required(VERSION 3.20)
project(search_engine)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

include(FetchContent)
FetchContent_Declare(
        json
        URL
        https://github.com/nlohmann/json/releases/download/v3.11.1/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_executable(search_engine src/main.cpp
        src/ConverterJSON.cpp include/ConverterJSON.h
        src/InvertedIndex.cpp include/InvertedIndex.h
        src/SearchServer.cpp  include/SearchServer.h
        src/CustomExceptions.cpp include/CustomExceptions.h)

target_include_directories(search_engine PUBLIC include)
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)