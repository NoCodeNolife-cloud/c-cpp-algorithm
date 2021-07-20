cmake_minimum_required(VERSION 3.19)
project(Queue)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(Queue main.cpp ListNode.cpp ListNode.h List.cpp List.h Queue.cpp Queue.h)