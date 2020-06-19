//
// Created by 陈志明 on 2020/5/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"
using namespace std;

/**
 * 题目描述：四数之和
 * 考点：数组，四指针
 * 是否做出：否
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.empty()) return {}; // 空数组
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int newTarget = target - nums[i]; // 将四数和转化为三数和

            for(int j=i+1; j<nums.size(); j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int newTarget2 = newTarget - nums[j]; // 将三数和转化为两数和

                int left=j+1, right=nums.size()-1;
                while(left < right){
                    if(nums[left]+nums[right] < newTarget2) left++;
                    else if(nums[left]+nums[right] > newTarget2) right--;
                    else{
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
    int target = -11;
    vector<vector<int>> res;
    res = Solution().fourSum(nums, target);

    for(int i=0; i<res.size(); i++){
        printVector(res[i]);
    }

    return 0;
}