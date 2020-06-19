//
// Created by 陈志明 on 2020/5/27.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "print.h"
using namespace std;

/**
 * 题目描述：全排列II
 * 考点：回溯算法
 * 是否做出：是
 */
class Solution {
private:
    set<vector<int>> res_set;

    void generatePermutation(vector<int> nums, int index, vector<int> p, vector<bool> visited){
        if(index == nums.size()){
            // 去重，其他解法？
            if(res_set.find(p) == res_set.end()){
                res_set.insert(p);
            }
            return;
        }

        // index表示当前处理第几个位置；visited访问过的元素不能再访问
        for(int i = 0; i < nums.size(); i++){
            if(visited[i])
                continue;
            p.push_back(nums[i]);
            visited[i] = true;
            generatePermutation(nums, index+1, p, visited);
            p.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return {};

        vector<int> p;
        vector<bool> visited(nums.size(), false);
        generatePermutation(nums, 0, p, visited);

        vector<vector<int>> res(res_set.begin(), res_set.end());
        return res;
    }
};


int main() {
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = Solution().permuteUnique(nums);

    for(int i=0; i<res.size(); i++)
        printVector(res[i]);

    return 0;
}