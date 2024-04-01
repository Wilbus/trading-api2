cmake_minimum_required(VERSION 3.10)
project(trading-api2-utils-mocks)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/SystemTimerMock.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-utils
    gmock
)