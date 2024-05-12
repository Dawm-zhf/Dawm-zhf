cmake_minimum_required(VERSION 3.28)
project(MatrixConjunctionProblem)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatrixConjunctionProblem main.cpp
        MatrixConjunction.cpp
        MatrixConjunction.h
)
