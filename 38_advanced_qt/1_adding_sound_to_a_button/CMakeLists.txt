cmake_minimum_required(VERSION 3.20)
project(1_adding_sound_to_a_button)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/Qt/5.15.2/msvc2019_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        Multimedia
        MultimediaWidgets)

add_executable(1_adding_sound_to_a_button main.cpp
        ImageButton.cpp ImageButton.h)
target_link_libraries(1_adding_sound_to_a_button
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets)
