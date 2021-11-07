cmake_minimum_required(VERSION 3.20)
project(v1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(v1
        liste.cc
        liste.h
        test_list.cc)
