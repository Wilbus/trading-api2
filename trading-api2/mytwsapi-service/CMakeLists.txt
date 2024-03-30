cmake_minimum_required(VERSION 3.10)
project(trading-api2-service)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/TwsClientWrapper.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/LiveMarketHandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/TwsLiveMarketService.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/mocks
)

target_link_libraries(${PROJECT_NAME} trading-api2-utils)
target_link_libraries(${PROJECT_NAME} trading-api2-charting)
target_link_libraries(${PROJECT_NAME} trading-api2-mytwasapi-imp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wno-unused-parameter -Wno-unused-variable -DLOG_FORMAT_VERIFICATION)