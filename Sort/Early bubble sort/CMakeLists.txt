cmake_minimum_required(VERSION 3.19)
project(Early_bubble_sort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Early_bubble_sort main.cpp)