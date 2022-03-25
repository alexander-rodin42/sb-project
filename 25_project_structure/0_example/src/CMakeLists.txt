cmake_minimum_required(VERSION 3.20)

add_executable(0_example main.cpp ${MY_INCLUDE_DIR}/my-math.h my-math.cpp)
target_include_directories(0_example PUBLIC ${MY_INCLUDE_DIR})
