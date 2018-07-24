cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_C_FLAGS "-Os -Wall -std=gnu99 -Wl,--gc-sections")
SET(CMAKE_CXX_FLAGS "-Os -Wall -Wl,--gc-sections -std=c++11")

add_executable(untitled main.cpp FIFO.cpp FIFO.hpp)