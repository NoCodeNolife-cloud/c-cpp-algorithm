cmake_minimum_required(VERSION 3.19)
project(List)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(List main.cpp ListNode.cpp ListNode.h List.cpp List.h)