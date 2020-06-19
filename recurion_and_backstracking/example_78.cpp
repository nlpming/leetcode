//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

/**
 * 题目描述：子集
 * 考点：数组、回溯算法
 * 是否做出：是
 */
class Solution {
private:
    vector<vector<int>> res;
    void generateSubsets(vector<int> nums, int start, vector<int> p){
        // 每次中间结果都存入res中
        res.push_back(p);

        for(int i = start; i < nums.size(); i++){
            p.push_back(nums[i]);
            generateSubsets(nums, i+1, p);
            p.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return res;

        vector<int> p;
        generateSubsets(nums, 0, p);

        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().subsets(nums);

    for(int i = 0; i < res.size(); i++){
        printVector(res[i]);
    }

    return 0;
}