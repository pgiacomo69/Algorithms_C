cmake_minimum_required(VERSION 3.22)
project(Algorithms_C)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        Matrix.h.h
        )
set(PROJECT_SOURCES
        main.cpp
        Matrix.cpp
        )


add_executable(Algorithms_C main.cpp Matrix.cpp Matrix.h MatrixMultiplier.h)
