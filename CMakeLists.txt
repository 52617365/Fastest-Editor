cmake_minimum_required(VERSION 3.21)
project(Editor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
add_executable(Editor main.cpp HelperFunctions.h ModeEnum.h Logic.cpp Logic.h Initialize.cpp Initialize.h)
