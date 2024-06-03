cmake_minimum_required(VERSION 3.10)
project(databank-scraping)

add_executable(databank-scraping)

#target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} PUBLIC
    trading-api2-databank
)

target_sources(${PROJECT_NAME}
  PRIVATE
  main.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wfatal-errors -DLOG_FORMAT_VERIFICATION)