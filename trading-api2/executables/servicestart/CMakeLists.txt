cmake_minimum_required(VERSION 3.10)
project(trading-service-start)

add_executable(trading-service-start)

#target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-service
)

target_sources(${PROJECT_NAME}
  PRIVATE
  main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)