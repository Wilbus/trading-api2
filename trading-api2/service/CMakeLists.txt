cmake_minimum_required(VERSION 3.10)
project(trading-api2-service)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/toplevel/src/TradingService.cpp
    ${CMAKE_CURRENT_LIST_DIR}/connection/src/SchwabConnectionManager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/agent/src/SimpleAgent.cpp
    ${CMAKE_CURRENT_LIST_DIR}/agent/src/TestAgent.cpp
    ${CMAKE_CURRENT_LIST_DIR}/agent/src/TestOptionsAgent.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/connection/include
    ${CMAKE_CURRENT_LIST_DIR}/toplevel/include
    ${CMAKE_CURRENT_LIST_DIR}/agent/include
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME}
    trading-api2-exchange
    trading-api2-streaming
    trading-api2-databank
    trading-api2-database-handlers
)


add_subdirectory(system-tests)