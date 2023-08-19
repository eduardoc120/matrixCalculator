cmake_minimum_required(VERSION 3.26)

set(This calcTests)

set(Sources
    CalcTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)
target_include_directories(${This} PRIVATE ${CMAKE_SOURCE_DIR})

add_test(
    NAME ${This}
    COMMAND ${This}
)

