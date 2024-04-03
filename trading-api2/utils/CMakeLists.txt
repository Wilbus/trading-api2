cmake_minimum_required(VERSION 3.10)
project(trading-api2-utils)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/FileWriter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/SystemTimer.cpp
)

target_include_directories(trading-api2-utils PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

find_package(RapidJSON)
find_package(ZLIB)
find_package(InfluxDB)


set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -Wno-unused-function -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)
target_link_libraries(${PROJECT_NAME} uWS)
target_link_libraries(${PROJECT_NAME} InfluxData::InfluxDB)


if(BUILD_TESTS)
    add_subdirectory(mocks)
endif(BUILD_TESTS)