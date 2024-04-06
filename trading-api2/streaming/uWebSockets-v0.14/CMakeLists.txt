cmake_minimum_required(VERSION 3.10)
project(uWebSockets-v0.14)

add_library(${PROJECT_NAME} SHARED
    ${CMAKE_CURRENT_LIST_DIR}/src/Epoll.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Extensions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Group.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/HTTPSocket.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Hub.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Networking.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Node.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Room.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Socket.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/WebSocket.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

find_package(ZLIB)
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL)
target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)

if(BUILD_TESTS)
    add_subdirectory(mocks)
endif(BUILD_TESTS)