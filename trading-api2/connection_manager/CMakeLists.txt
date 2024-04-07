cmake_minimum_required(VERSION 3.10)
project(trading-api2-connection-manager)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/SchwabConnectionManager.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME} trading-api2-exchange)
target_link_libraries(${PROJECT_NAME} trading-api2-streaming)

if(BUILD_TESTS)
    #add_subdirectory(schwab/mocks)
endif(BUILD_TESTS)