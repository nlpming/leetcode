//
// Created by 陈志明 on 2020/5/27.
//
#include <iostream>
#include <vector>
#include "print.h"
using namespace std;

/**
 * 题目描述：全排列
 * 考点：回溯算法
 * 是否做出：是
 */
class Solution {
private:
    vector<vector<int>> res;

    void generatePermutation(vector<int> nums, int index, vector<int> p, vector<bool> visited){
        if(index == nums.size()){
            res.push_back(p);
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
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.empty())
            return res;

        vector<int> p;
        vector<bool> visited(nums.size(), false);
        generatePermutation(nums, 0, p, visited);

        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().permute(nums);

    for(int i=0; i<res.size(); i++)
        printVector(res[i]);

    return 0;
}