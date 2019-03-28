cmake_minimum_required(VERSION 3.13)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp model/VictimFile.cpp model/VictimFile.h repository/DynamicVector.h ui/Scanner.cpp ui/Scanner.h service/VictimFileService.cpp service/VictimFileService.h test/Test.cpp test/Test.h model/Mode.cpp model/Mode.h)