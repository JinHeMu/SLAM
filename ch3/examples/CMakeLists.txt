cmake_minimum_required(VERSION 3.15)

include_directories("/usr/include/eigen3")

# set the project name
project(coordinateTransform.cpp)

# add the executable
add_executable(coordinateTransform coordinateTransform.cpp)

project(plotTrajectory.cpp)



find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})