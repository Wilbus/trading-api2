cmake_minimum_required(VERSION 3.10)
project(trading-backtester-exe)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-backtester-tester
)

target_sources(${PROJECT_NAME}
  PRIVATE
  main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)