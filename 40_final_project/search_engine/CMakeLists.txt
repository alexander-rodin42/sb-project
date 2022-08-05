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

include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_executable(search_engine src/main.cpp
        src/ConverterJSON.cpp include/ConverterJSON.h
        src/InvertedIndex.cpp include/InvertedIndex.h
        src/SearchServer.cpp  include/SearchServer.h
        src/CustomExceptions.cpp include/CustomExceptions.h)

target_include_directories(search_engine PUBLIC include)
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(search_engine PUBLIC gtest_main)
target_link_libraries(search_engine PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(search_engine)
