cmake_minimum_required(VERSION 3.27)
project(audio_prng C)

set(CMAKE_C_STANDARD 11)

add_executable(audio_prng
        main.c
        lcg.h
        lcg.c
        time_since.h
        time_since.c
)