cmake_minimum_required(VERSION 3.10)
project(trading-api2-database-ut)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC")

enable_testing()

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/InfluxDbTests.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-database
    trading-api2-logging-mocks
    gtest_main
    gmock
)

target_include_directories(${PROJECT_NAME} PUBLIC
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wno-unused-function -DLOG_FORMAT_VERIFICATION)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})