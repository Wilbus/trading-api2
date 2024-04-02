cmake_minimum_required(VERSION 3.10)
project(trading-api2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC")

option(BUILD_TESTS "Build tests option" OFF)
set(GOOGLETEST_VERSION "1.14.0")

add_subdirectory(exchanges)
add_subdirectory(charting)
add_subdirectory(restclient)
add_subdirectory(streaming)
add_subdirectory(utils)
add_subdirectory(executables)
add_subdirectory(googletest-1.14.0)

message(STATUS "BUILD_TESTS is ${BUILD_TESTS}")

if(BUILD_TESTS)
    add_subdirectory(unit_tests)
endif(BUILD_TESTS)