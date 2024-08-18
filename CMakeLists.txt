cmake_minimum_required(VERSION 3.26)
project(TuringLanguage)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(TuringLanguage main.cpp
        main.h
        turingmachine.cpp
        turingmachine.h
        fileparser.cpp
        fileparser.h
        basic.h
        statement.cpp
        statement.h
        log.cpp)