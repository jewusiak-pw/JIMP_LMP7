cmake_minimum_required(VERSION 3.20)
project(JIMP_LMP7 C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(JIMP_LMP7 indx4.c list.c list.h skorowidz.c skorowidz.h)
