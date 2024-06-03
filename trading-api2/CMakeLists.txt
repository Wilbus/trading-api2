cmake_minimum_required(VERSION 3.10)
project(trading-api2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC")

set(GOOGLETEST_VERSION "1.14.0")

add_subdirectory(utils)
add_subdirectory(exchanges)
add_subdirectory(configs)
add_subdirectory(charting)
add_subdirectory(database)
add_subdirectory(database-handlers)
add_subdirectory(databank)
add_subdirectory(logging)
add_subdirectory(restclient)
add_subdirectory(streaming)
add_subdirectory(uWebSockets-v0.14)
add_subdirectory(exchange-datatypes)
add_subdirectory(service)



add_subdirectory(googletest-1.14.0)
add_subdirectory(executables)
