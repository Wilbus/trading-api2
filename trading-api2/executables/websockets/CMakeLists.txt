cmake_minimum_required(VERSION 3.10)
project(schwabsocket)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fPIC -lcrypto -lssl")

add_executable(schwabsocket)

target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-streaming
    trading-api2-utils
)

target_sources(${PROJECT_NAME}
  PRIVATE
  schwabsocket.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)