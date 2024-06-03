cmake_minimum_required(VERSION 3.10)
project(trading-api2-configs)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/SchwabConfigs.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} 
    trading-api2-exchange-datatypes
    trading-api2-utils
)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)


add_subdirectory(mocks)
add_subdirectory(ut)