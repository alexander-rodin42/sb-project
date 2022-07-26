cmake_minimum_required(VERSION 3.20)
project(0_example3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/Qt/5.15.2/msvc2019_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)

add_executable(0_example3 main.cpp)
target_link_libraries(0_example3
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets)
