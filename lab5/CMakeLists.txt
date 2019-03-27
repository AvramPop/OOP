cmake_minimum_required(VERSION 3.13)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp VictimFile.cpp VictimFile.h DynamicVector.h Scanner.cpp Scanner.h VictimFileService.cpp VictimFileService.h Test.cpp Test.h)