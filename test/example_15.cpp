//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "print.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 2)
            return res;

        // 对数组进行排序
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            // 去除重复
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i+1;
            int right = nums.size()-1;
            int target = -nums[i];

            // 两数之和
            while(left < right){
                if(nums[left] + nums[right] > target)
                    right--;
                else if(nums[left] + nums[right] < target)
                    left++;
                else{
                    // 插入一个一维数组
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    // 去除重复
                    while(left < right && nums[left] == nums[left-1])
                        left++;
                    while(left < right && nums[right] == nums[right+1])
                        right--;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    res = Solution().threeSum(nums);

    for(int i = 0; i < res.size(); i++){
        printVector(res[i]);
    }

    return 0;
}
