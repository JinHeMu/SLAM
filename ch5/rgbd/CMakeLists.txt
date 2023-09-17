cmake_minimum_required(VERSION 3.15)

project(joinMap)

include_directories("/home/jinhemu/slam/Sophus")
find_package(Sophus REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

find_package(Pangolin REQUIRED)
find_package(fmt REQUIRED)



add_executable(joinMap joinMap.cpp)
target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES})
target_link_libraries(joinMap fmt::fmt)