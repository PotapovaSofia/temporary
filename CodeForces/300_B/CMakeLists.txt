cmake_minimum_required(VERSION 3.1)
project(300_B)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(300_B ${SOURCE_FILES})