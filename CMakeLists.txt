cmake_minimum_required(VERSION 3.26)
project(TuringLanguage)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(TuringLanguage src/main.cpp
        include/main.h
        src/turingmachine.cpp
        include/turingmachine.h
        src/fileparser.cpp
        include/fileparser.h
        include/basic.h
        src/statement.cpp
        include/statement.h)