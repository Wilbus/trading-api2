cmake_minimum_required(VERSION 3.10)
project(twslivemarket)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(twslivemarket)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wno-unused-parameter -Wno-unused-variable -DLOG_FORMAT_VERIFICATION)


target_link_libraries(twslivemarket PUBLIC
    trading-api2-service
)

target_sources(twslivemarket
    PRIVATE
    twslivemarket.cpp)