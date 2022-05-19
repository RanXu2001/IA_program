cmake_minimum_required(VERSION 3.22)
project(IA_program C)

set(CMAKE_C_STANDARD 11)

include_directories(Structure)

add_executable(IA_program
        Structure/structure.c)
