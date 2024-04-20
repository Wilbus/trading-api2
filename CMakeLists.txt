cmake_minimum_required(VERSION 3.10)
project(trading-app)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC")


add_subdirectory(trading-api2)
add_subdirectory(backtester)