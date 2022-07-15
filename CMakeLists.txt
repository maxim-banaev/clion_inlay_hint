cmake_minimum_required(VERSION 3.23)
project(clion_inlay_hint)

set(CMAKE_CXX_STANDARD 17)

add_executable(clion_inlay_hint main.cpp types/variable.cpp)
