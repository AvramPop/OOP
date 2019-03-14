cmake_minimum_required(VERSION 3.13)
project(lab3 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab3 main.c File.h FileRepository.h FileRepository.c File.c Console.h Console.c)