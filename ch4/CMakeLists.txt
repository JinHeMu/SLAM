cmake_minimum_required(VERSION 2.8)
project(use_sophus)
set(CMAKE_BUILD_TYPE "Debug" )
find_package(Sophus REQUIRED)

include_directories( ${Sophus_INCLUDE_DIRS} )
include_directories("/usr/include/eigen3")
add_executable(usesophus useSophus.cpp)
target_link_libraries(usesophus Sophus::Sophus)