cmake_minimum_required(VERSION 3.16)
project(clion_inlay_hint)

set(CMAKE_CXX_STANDARD 20)

add_executable(clion_inlay_hint main.cpp
        types/variable.cpp
        types/lambdas.cpp
        types/return.cpp
        types/parameter.cpp
        types/template.cpp

        parameters/enum.cpp
        parameters/constructor.cpp
        parameters/reference.cpp
        parameters/index.cpp
        parameters/hint.cpp)
