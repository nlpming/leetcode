cmake_minimum_required(VERSION 3.10)
project(workspace)

# 添加头文件
include_directories(./include)

set(CMAKE_CXX_STANDARD 11)

# 排序问题
#add_executable(leetcode-c++ sort_algorithm/merge_sort_v2.cpp)

# 数组、字符串问题
#add_executable(leetcode-c++ array_problem/28[not]_implement-strstr.cpp)

# 哈希表问题
#add_executable(leetcode-c++ hash_table/16_3sum-closest.cpp)

# 链表问题
add_executable(leetcode-c++ link_list/148_sort-list.cpp)

# 栈、队列、堆问题
#add_executable(leetcode-c++ stack_and_queue/127_word-ladder.cpp)

# 递归、回溯问题；
#add_executable(leetcode-c++ recurion_and_backstracking/131[not]_palindrome-partitioning.cpp)

# 动态规划问题
#add_executable(leetcode-c++ dynamic_programming/322[not]_coin-change.cpp)

# 二叉树、二叉搜索树问题
#add_executable(leetcode-c++ binary_tree/binary_search_tree.cpp)

