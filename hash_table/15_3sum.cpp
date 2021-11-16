//
// Created by 陈志明 on 2021/8/23.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "print.h"

using namespace std;

/*
 * 考点：三指针；
 * */
class Solution {
public:
    //两数之和
    vector<vector<int>> twoSum(vector<int> nums, int left, int right, int target){
        vector<vector<int>> res;
        while(left < right){
            if(nums[left] + nums[right] == target){
                res.push_back({nums[left], nums[right]});
                left++;
                right--;

                //left,right位置重复去重；
                while(left < right && nums[left] == nums[left-1])
                    left++;
                while(left < right && nums[right] == nums[right+1])
                    right--;
            }else if(nums[left] + nums[right] > target)
                right--;
            else
                left++;
        }

        return res;
    }

    /*
     * 解题思路：
     * 1. 首先对数组进行排序；
     * 2. 使用三指针：cur -> 指向当前位置；left -> cur+1；right -> nums.size()-1；
     * 3. 将三数之和问题转换为两数之和；
     * 4. 如何做到去重？
     * （1）对数组进行排序；
     * （2）当前位置cur，进行去重：nums[cur] == nums[cur-1]
     * （3）left,right位置进行去重：如果找到答案，判断nums[left] == nums[left-1], nums[right] == nums[right+1]
     * */
    vector<vector<int>> threeSum(vector<int>& nums) {
        //对数组进行排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int cur = 0; cur < nums.size(); cur++){
            if(cur > 0 && nums[cur] == nums[cur-1]) //cur位置重复去重；
                continue;

            int left = cur+1, right = nums.size()-1;
            int target = -nums[cur];
            vector<vector<int>> tmp = twoSum(nums, left, right, target);
            for(int i = 0; i < tmp.size(); i++){
                tmp[i].insert(tmp[i].begin(), nums[cur]); //cur插入到数组开始位置；
                res.push_back(tmp[i]);
            }
        }

        return res;
    }
};

int main(){

    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> res = s.threeSum(nums);
    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);

    return 0;
}