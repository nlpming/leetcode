//
// Created by 陈志明 on 2020/5/13.
//
#include <iostream>
#include <vector>
#include <map>
#include "print.h"

using namespace std;

/**
 * 题目描述：两数之和
 * 考点：哈希表
 * 是否做出：是
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map存储：num和其index
        map<int, int> num_index_map;
        vector<int> res;

        for(int i=0; i<nums.size(); i++){
            int other = target-nums[i];
            if(num_index_map.find(other) == num_index_map.end())
                num_index_map[nums[i]] = i;
            else{
                res.push_back(i);
                res.push_back(num_index_map[other]);
            }
        }

        return res;
    }
};

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;

    printVector(Solution().twoSum(nums, target));

    return 0;
}


