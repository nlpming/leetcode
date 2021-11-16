//
// Created by 陈志明 on 2021/11/15.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include "print.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //存放内容：target - nums[i] -> i
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); i++){
            int tmp = target - nums[i];

            //查找当前元素是否存在
            if(record.find(nums[i]) != record.end())
                return {record[nums[i]], i};
            else
                record[tmp] = i;
        }

        return {-1, -1};
    }
};

int main(){

    vector<int> nums = {3,2,4};
    Solution s;

    printVector(s.twoSum(nums, 6));

    return 0;
}
