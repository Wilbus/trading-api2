cmake_minimum_required(VERSION 3.10)
project(trading-api2-streaming)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/TradierStreamHandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/AlpacaStreamHandler.cpp
)

target_include_directories(trading-api2-streaming PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/mocks
)

target_link_libraries(${PROJECT_NAME} trading-api2-utils)