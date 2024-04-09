cmake_minimum_required(VERSION 3.10)
project(trading-api2-exchange-datatypes)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/schwab/include
)

target_link_libraries(${PROJECT_NAME} INTERFACE
    trading-api2-utils
)

if(BUILD_TESTS)
    add_subdirectory(schwab/stubfiles)
    add_subdirectory(schwab/ut)
endif(BUILD_TESTS)