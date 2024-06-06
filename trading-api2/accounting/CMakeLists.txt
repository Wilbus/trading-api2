cmake_minimum_required(VERSION 3.10)
project(trading-api2-accounting)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/AccountDetails.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(${PROJECT_NAME} trading-api2-utils)

#add_subdirectory(ut)