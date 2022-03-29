cmake_minimum_required(VERSION 3.20)
project(voronoi)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(voronoi main.cpp)
