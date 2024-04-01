cmake_minimum_required(VERSION 3.10)
project(trading-api2-streaming)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/SchwabStreamHandler.cpp
)

target_include_directories(trading-api2-streaming PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} trading-api2-utils)

if(BUILD_TESTS)
    add_subdirectory(mocks)
endif(BUILD_TESTS)