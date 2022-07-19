cmake_minimum_required(VERSION 3.20)
project(3_tv_remote_control)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(3_tv_remote_control main.cpp
        tvRemoteControl.ui
        MainTvRemoteControl.cpp MainTvRemoteControl.h)

target_link_libraries(3_tv_remote_control
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)

