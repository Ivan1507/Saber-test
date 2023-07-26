cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

add_executable(1 1.cpp)
add_executable(2 2.cpp)
add_executable(3 3.cpp)
