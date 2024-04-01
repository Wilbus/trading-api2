cmake_minimum_required(VERSION 3.10)
project(trading-api2-exchange-mocks)

add_library(${PROJECT_NAME} INTERFACE
)

target_include_directories(${PROJECT_NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME} INTERFACE
    gmock
)