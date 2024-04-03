cmake_minimum_required(VERSION 3.10)
project(libcurlposttest)

add_executable(libcurlposttest)

#target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-exchange
    trading-api2-utils
)

target_sources(${PROJECT_NAME}
  PRIVATE
  libcurlposttest.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)