cmake_minimum_required(VERSION 3.10)
project(trading-api2-exchange)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/schwab/src/SchwabClient.cpp
    ${CMAKE_CURRENT_LIST_DIR}/schwab/src/SchwabConfigs.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/schwab/include
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME} trading-api2-restclient)
target_link_libraries(${PROJECT_NAME} trading-api2-streaming)
target_link_libraries(${PROJECT_NAME} trading-api2-charting)

if(BUILD_TESTS)
    add_subdirectory(schwab/mocks)
endif(BUILD_TESTS)