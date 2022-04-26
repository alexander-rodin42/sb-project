cmake_minimum_required(VERSION 3.20)
project(3_simulation_of_the_company)

set(CMAKE_CXX_STANDARD 14)

add_executable(3_simulation_of_the_company src/main.cpp
        include/Employee.h src/Employee.cpp
        include/CompanyHead.h src/CompanyHead.cpp
        include/Manager.h src/Manager.cpp
        include/StaffMember.h src/StaffMember.cpp)

target_include_directories(3_simulation_of_the_company PUBLIC include)

