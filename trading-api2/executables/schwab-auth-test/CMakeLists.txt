cmake_minimum_required(VERSION 3.10)
project(schwab-auth-test)

add_executable(schwab-auth-test)

#target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-exchange
    trading-api2-utils
)

target_sources(${PROJECT_NAME}
  PRIVATE
  schwab-auth-test.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)