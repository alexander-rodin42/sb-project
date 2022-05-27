cmake_minimum_required(VERSION 3.20)
project(2_graph_class_implementation)

set(CMAKE_CXX_STANDARD 14)

add_executable(2_graph_class_implementation src/main.cpp
        src/IGraph.cpp include/IGraph.h
        src/ListGraph.cpp include/ListGraph.h
        src/MatrixGraph.cpp include/MatrixGraph.h)

target_include_directories(2_graph_class_implementation PUBLIC include)
