cmake_minimum_required(VERSION 3.14)
project(TSP)

set(CMAKE_CXX_STANDARD 11)

add_executable(TSP main.cpp City.cpp City.h greedy.cpp greedy.h)