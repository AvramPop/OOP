cmake_minimum_required(VERSION 3.13)
project(lab6_reloaded)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab6_reloaded main.cpp Mode.cpp Mode.h VictimFile.cpp VictimFile.h FileRepository.h Scanner.cpp Scanner.h Test.cpp Test.h VictimFileService.cpp VictimFileService.h)