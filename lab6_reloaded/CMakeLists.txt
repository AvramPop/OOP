cmake_minimum_required(VERSION 3.13)
project(lab6_reloaded)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_executable(lab6_reloaded main.cpp Mode.cpp Mode.h VictimFile.cpp VictimFile.h FileRepository.h Scanner.cpp Scanner.h Test.cpp Test.h VictimFileService.cpp VictimFileService.h Repository.h Exception.h Validator.cpp Validator.h MockRepository.cpp MockRepository.h FileSaver.cpp FileSaver.h)