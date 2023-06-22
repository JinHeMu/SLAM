cmake_minimum_required(VERSION 3.15)

include_directories("/usr/include/eigen3")

# set the project name
project(eitenMatrix.cpp)

# add the executable
add_executable(eitenMatrix eitenMatrix.cpp)