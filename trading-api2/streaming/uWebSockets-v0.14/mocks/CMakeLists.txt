cmake_minimum_required(VERSION 3.10)
project(uWebSockets-v0.14-mocks)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/WebSocketMock.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    uWebSockets-v0.14
    gmock
)