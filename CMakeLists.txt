project(usefulcxx)
cmake_minimum_required(VERSION 3.22)

add_compile_definitions(USEFULCXX_ALLOW_EXCEPTIONS)
include_directories(${CMAKE_SOURCE_DIR})

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++17 -ggdb")

add_subdirectory(usefulcxx)
add_subdirectory(examples)
