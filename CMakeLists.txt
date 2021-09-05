cmake_minimum_required(VERSION 3.10)
project(workspace)

# 添加头文件
include_directories(./include)

set(CMAKE_CXX_STANDARD 11)

#add_executable(leetcode-c++ sort_algorithm/merge_sort.cpp)

#add_executable(leetcode-c++ array_problem/vector.cpp)

#add_executable(leetcode-c++ hash_table/16_3sum-closest.cpp)

#add_executable(leetcode-c++ link_list/143[not]_reorder-list.cpp)

#add_executable(leetcode-c++ stack_and_queue/127_word-ladder.cpp)

#add_executable(leetcode-c++ test/merge_sort.cpp)

#add_executable(leetcode-c++ recurion_and_backstracking/131[not]_palindrome-partitioning.cpp)

add_executable(leetcode-c++ dynamic_programming/01_knapsack.cpp)

