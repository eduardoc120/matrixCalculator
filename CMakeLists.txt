cmake_minimum_required(VERSION 3.26)

set(This Example)

project(${This} C CXX)

# GoogleTest requires at least C++14
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest-main) # add googletest subdirectory

set(Headers
    matrix_calculator.hpp
)
set(Sources
    matrix_calculator.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
