cmake_minimum_required(VERSION 3.0)

project(trajectoryError)


find_package(Pangolin REQUIRED)
find_package(fmt REQUIRED)


include_directories("/home/jinhemu/slam/Sophus")
include_directories(${Pangolin_INCLUDE_DIRS})


add_executable(trajectoryError trajectoryError.cpp)
target_link_libraries(trajectoryError ${Pangolin_LIBRARIES} fmt::fmt)
