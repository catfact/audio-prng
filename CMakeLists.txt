cmake_minimum_required(VERSION 3.11)
project(audio_prng C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(audio_prng
        main.c
        lcg.h
        lcg.c
        time_since.h
        time_since.c
)