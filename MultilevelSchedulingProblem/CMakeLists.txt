cmake_minimum_required(VERSION 3.28)
project(MultilevelSchedulingProblem)

set(CMAKE_CXX_STANDARD 11)

add_executable(MultilevelSchedulingProblem main.cpp
        MultilevelScheduling.cpp
        MultilevelScheduling.h)
