cmake_minimum_required(VERSION 3.10)
project(schwab-auth-test)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_executable(schwab-auth-test)

target_compile_options(schwab-auth-test PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)


target_link_libraries(schwab-auth-test PUBLIC
    trading-api2-exchange
    trading-api2-restclient
    trading-api2-streaming
)

target_sources(schwab-auth-test
    PRIVATE
    schwab-auth-test.cpp)