//
// Created by 陈志明 on 2020/6/8.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void generateSubset(vector<int> nums, int index, vector<int> temp){
        res.push_back(temp);
        if(index == nums.size())
            return;

        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            generateSubset(nums, i+1, temp); // 注意此处 i+1
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return res;

        vector<int> temp;
        generateSubset(nums, 0, temp);

        return res;
    }
};