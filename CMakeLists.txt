cmake_minimum_required(VERSION 3.30)
project(malloc C)

set(CMAKE_C_STANDARD 11)

add_executable(malloc
        ex1.c
        ex1.h
        ex2.c
        ex2.h
        ex3.c
        ex3.h
        main.c
)
