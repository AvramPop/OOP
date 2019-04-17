cmake_minimum_required(VERSION 3.13)
project(sem2 C)

set(CMAKE_C_STANDARD 99)

add_executable(sem2 main.c Planet.h Planet.c DynamicVector.c DynamicVector.h)