cmake_minimum_required(VERSION 3.10)
project(trading-api2-tests)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC")

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-exchange
    trading-api2-exchange-mocks
    trading-api2-restclient
    trading-api2-restclient-mocks
    trading-api2-streaming
    trading-api2-streaming-mocks
    trading-api2-utils
    trading-api2-utils-mocks
    gtest_main
    gmock
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/testfiles
)

target_sources(${PROJECT_NAME}
  PRIVATE
  main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)