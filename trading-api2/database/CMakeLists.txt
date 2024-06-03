cmake_minimum_required(VERSION 3.10)
project(trading-api2-database)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/InfluxDbPusher.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

find_package(InfluxDB)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME}
    trading-api2-logging
    trading-api2-utils
    InfluxData::InfluxDB
)


add_subdirectory(mocks)
add_subdirectory(ut)