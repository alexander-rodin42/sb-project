cmake_minimum_required(VERSION 3.20)
project(2_mobile_phone_simulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_mobile_phone_simulation src/main.cpp
        include/MobilePhone.h src/MobilePhone.cpp
        include/Person.h src/Person.cpp
        include/Verification.h src/Verification.cpp)

target_include_directories(2_mobile_phone_simulation PUBLIC include)
