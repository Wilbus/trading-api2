cmake_minimum_required(VERSION 3.10)
project(trading-api2-utils)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/FileWriter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SystemTimer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/CurlWrapperFuncs.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Timer.cpp
)

target_include_directories(trading-api2-utils PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

find_package(RapidJSON)
#find_package(InfluxDB)
find_package(CURL REQUIRED)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)
#target_link_libraries(${PROJECT_NAME} InfluxData::InfluxDB)
target_link_libraries(${PROJECT_NAME} CURL::libcurl)


if(BUILD_TESTS)
    add_subdirectory(mocks)
    add_subdirectory(ut)
endif(BUILD_TESTS)