cmake_minimum_required(VERSION 3.22)
project(IA_program)

set(CMAKE_CXX_STANDARD 14)

include_directories(POP3CW)

add_executable(IA_program
        POP3CW/blueprint
        POP3CW/structure.c
        POP3CW/TCP.c
        POP3CW/TCP1.c)
