cmake_minimum_required(VERSION 3.10)
project(workspace)

# 添加头文件
include_directories(./include)

set(CMAKE_CXX_STANDARD 11)

add_executable(leetcode-c++ test/example_3.cpp)
#add_executable(workspace sort_algorithm.cpp)


