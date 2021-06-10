# cmake_minimum_required(VERSION <specify CMake version here>)
project(Lab1_main C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab1_main
        complex_vector.c
        complex_vector.h
        float_vector.c
        float_vector.h
        interface.c
        interface.h
        main.c
        tests.c
        tests.h
        vector.c
        vector.h)
