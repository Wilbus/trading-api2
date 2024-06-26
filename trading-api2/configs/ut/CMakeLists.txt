cmake_minimum_required(VERSION 3.10)
project(trading-api2-configs-ut)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC")

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/SchwabConfigsTest.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-configs
    gtest_main
    gmock
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/stubfiles
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wno-unused-function -DLOG_FORMAT_VERIFICATION)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})