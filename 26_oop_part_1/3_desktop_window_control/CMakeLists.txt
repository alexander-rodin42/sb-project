cmake_minimum_required(VERSION 3.20)
project(3_desktop_window_control)

set(CMAKE_CXX_STANDARD 14)

add_executable(3_desktop_window_control src/main.cpp
        include/ScreenResolution.h
        include/Display.h src/Display.cpp
        include/Window.h src/Window.cpp)

target_include_directories(3_desktop_window_control PUBLIC include)
