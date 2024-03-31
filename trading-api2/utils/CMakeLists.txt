cmake_minimum_required(VERSION 3.10)
project(trading-api2-utils)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/FileWriter.cpp
)

target_include_directories(trading-api2-utils PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/eb80f759d595874a5e905a3342bd8e2af4c0a12d.zip
)
FetchContent_MakeAvailable(googletest)

find_package(RapidJSON)
find_package(ZLIB)
find_package(InfluxDB)


set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -Wunused-parameter -Wunused-variable -DLOG_FORMAT_VERIFICATION)
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)
target_link_libraries(${PROJECT_NAME} uWS)
target_link_libraries(${PROJECT_NAME} InfluxData::InfluxDB)
target_link_libraries(${PROJECT_NAME} gmock)