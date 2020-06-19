//
// Created by 陈志明 on 2020/5/13.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "print.h"

using namespace std;

/**
 * 题目描述：三数之和
 * 考点：数组，三指针，对撞指针
 * 是否做出：否
 * NOTE: 如何做到去重？
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // 首先，对数组nums进行排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // 碰到重复元素跳过
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int newTarget = - nums[i]; // 三数和变两数和

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] < newTarget)
                    ++left;
                else if (nums[left] + nums[right] > newTarget)
                    --right;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    ++left, --right;
                    // 碰到重复元素跳过
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums={-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    res = Solution().threeSum(nums);

    for(int i=0; i<res.size(); i++){
        printVector(res[i]);
    }

    return 0;
}