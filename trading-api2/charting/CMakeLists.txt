cmake_minimum_required(VERSION 3.10)
project(trading-api2-charting)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/IndicatorTypes.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/CandleStick.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/ChartData2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/ta-lib-wrapper.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} trading-api2-utils)
target_link_libraries(${PROJECT_NAME} libta_lib.so)