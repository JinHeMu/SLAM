cmake_minimum_required(VERSION 3.15)

include_directories("/usr/include/eigen3")

# set the project name
project(useGeometry.cpp.cpp)

# add the executable
add_executable(useGeometry useGeometry.cpp)