cmake_minimum_required(VERSION 3.10)
project(workspace)

# 添加头文件
include_directories(./include)

set(CMAKE_CXX_STANDARD 11)

#add_executable(leetcode-c++ sort_algorithm/merge_sort.cpp)

#add_executable(leetcode-c++ array_problem/vector.cpp)

add_executable(leetcode-c++ sort_algorithm/quick_sort.cpp)




