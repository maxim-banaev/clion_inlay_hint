cmake_minimum_required(VERSION 3.23)
project(clion_inlay_hint)

set(CMAKE_CXX_STANDARD 20)

add_executable(clion_inlay_hint main.cpp
        types/variable.cpp
        types/lambdas.cpp
        types/return.cpp
        types/parameter.cpp

        parameters/enum.cpp
        parameters/constructor.cpp
        parameters/reference.cpp
        parameters/index.cpp
        parameters/hint.cpp)
