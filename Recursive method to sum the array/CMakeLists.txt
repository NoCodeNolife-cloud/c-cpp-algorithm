cmake_minimum_required(VERSION 3.19)
project(Recursive_method_to_sum_the_array)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(Recursive_method_to_sum_the_array main.cpp)