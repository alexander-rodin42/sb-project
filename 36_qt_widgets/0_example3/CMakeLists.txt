cmake_minimum_required(VERSION 3.20)
project(0_example3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "E:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(0_example3 main.cpp)

target_link_libraries(0_example3
        Qt5::Widgets
        Qt5::Core
        Qt5::Gui)