project(usefulcxx)
cmake_minimum_required(VERSION 3.22)

add_compile_definitions(USEFULCXX_ALLOW_EXCEPTIONS)
include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_BUILD_TYPE DEBUG)

set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(WARNING_FLAGS " -Wall -Wextra -pedantic")
set(CXX_STD_FLAG " -std=c++17")

set(CMAKE_CXX_FLAGS_DEBUG "${WARNING_FLAGS} ${CXX_STD_FLAG} -ggdb")

add_subdirectory(usefulcxx)
add_subdirectory(examples)
add_subdirectory(patterns)
