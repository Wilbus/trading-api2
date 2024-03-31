cmake_minimum_required(VERSION 3.10)
project(trading-api2-exchange)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/tradier/src/TradierData.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tradier/src/CandleSampler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/alpaca/src/AlpacaClient.cpp
    ${CMAKE_CURRENT_LIST_DIR}/schwab/src/SchwabClient.cpp
    ${CMAKE_CURRENT_LIST_DIR}/schwab/src/SchwabConfigs.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/alpaca/include
    ${CMAKE_CURRENT_LIST_DIR}/schwab/include
    ${CMAKE_CURRENT_LIST_DIR}/schwab/mocks
    ${CMAKE_CURRENT_LIST_DIR}/tradier/include
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME} trading-api2-restclient)
target_link_libraries(${PROJECT_NAME} trading-api2-streaming)
target_link_libraries(${PROJECT_NAME} trading-api2-charting)