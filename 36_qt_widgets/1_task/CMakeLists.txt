cmake_minimum_required(VERSION 3.20)
project(1_task)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(1_task main.cpp)

target_link_libraries(1_task
        Qt5::Widgets
        Qt5::Core
        Qt5::Gui)

target_include_directories(1_task PUBLIC include)