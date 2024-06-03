cmake_minimum_required(VERSION 3.10)
project(trading-api2-databank)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/ChartsAggregator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SchwabDatabank.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME}
    trading-api2-exchange
    trading-api2-exchange-datatypes
    trading-api2-database-handlers
    trading-api2-streaming
    trading-api2-charting
    trading-api2-database
    trading-api2-utils
)


add_subdirectory(ut)