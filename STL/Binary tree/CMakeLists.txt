cmake_minimum_required(VERSION 3.19)
project(Binary_tree)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "-static")

add_executable(Binary_tree main.cpp BinTree.h BinTree.h)