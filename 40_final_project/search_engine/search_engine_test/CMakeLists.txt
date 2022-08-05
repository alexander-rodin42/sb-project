cmake_minimum_required(VERSION 3.20)
project(search_engine_test)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_executable(search_engine_test main.cpp)

target_include_directories(search_engine_test PUBLIC gtest_main)
target_link_libraries(search_engine_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(search_engine_test)