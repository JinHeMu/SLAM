cmake_minimum_required(VERSION 3.0)


project(imageBasics)


find_package(OpenCV REQUIRED)
add_executable(imageBasics imageBasics.cpp)
# 链接OpenCV库

target_link_libraries(imageBasics ${OpenCV_LIBS})

add_executable(undistortImage undistortImage.cpp)
# 链接OpenCV库
target_link_libraries(undistortImage ${OpenCV_LIBS})
