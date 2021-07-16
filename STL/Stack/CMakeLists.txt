cmake_minimum_required(VERSION 3.19)
project(Stack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(Stack main.cpp Vector.cpp Vector.h Stack.cpp Stack.h)