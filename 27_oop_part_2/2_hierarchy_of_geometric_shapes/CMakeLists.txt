cmake_minimum_required(VERSION 3.20)
project(2_hierarchy_of_geometric_shapes)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_hierarchy_of_geometric_shapes src/main.cpp
        include/GeometricFigure.h src/GeometricFigure.cpp
        include/Circle.h src/Circle.cpp
        include/EquilateralTriangle.h src/EquilateralTriangle.cpp
        include/Square.h src/Square.cpp
        include/Rectangle.h src/Rectangle.cpp)

target_include_directories(2_hierarchy_of_geometric_shapes PUBLIC include)