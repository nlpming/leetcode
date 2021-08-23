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
    //两数之和: 数组已排好序
    vector<vector<int>> twoSum(vector<int> nums, int cur, int left, int right, int target){
        vector<vector<int>> res;
        unordered_map<int, int> record; //记录两个数

        while(left < right){
            if(nums[left] + nums[right] == target){
                // 方法一：
                /*
                if(left > cur+1 && nums[left] == nums[left-1]){ //NOTE: 此处用于去重；
                    left++;
                    continue;
                }

                vector<int> tmp;
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);
                res.push_back(tmp);
                */

                // 方法二：
                if(record.find(nums[left]) == record.end() && record.find(nums[right]) == record.end()){
                    vector<int> tmp;
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);

                    record[nums[left]] = nums[right];
                }

                left++;
                right--;
            }else if(nums[left] + nums[right] > target){
                right--;
            }else{
                left++;
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int left, right;

        //解题思路：
        // 1. 将三数之和转为两数之和；cur指向当前的数nums[i]，left,right指针分别指向cur之后的数组开始和结束位置；
        // 2. nums[left...right]确定的新的数组，即求解两数之和 target - nums[i];
        // 3. 如何保证不产生重复结果？
        //（1）对数组nums进行排序；
        //（2）当cur>0的时候，判断是否nums[cur] == nums[cur-1]；如果出现这种情况跳过；
        //（3）求两数之和时判断：nums[left] == nums[left-1]；如果出现这种情况left++，并跳过；

        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end());
        for(int cur = 0; cur < nums.size()-2; cur++){
            if(cur > 0 && nums[cur] == nums[cur-1]){ //NOTE: 此处保证不会产生重复结果；
                continue;
            }

            left = cur+1;
            right = nums.size()-1;

            vector<vector<int>> tmp;
            tmp = twoSum(nums, cur, left, right, 0 - nums[cur]);
            for(int k = 0; k < tmp.size(); k++){
                tmp[k].push_back(nums[cur]);
                res.push_back(tmp[k]);
            }
        }

        return res;
    }
};

int main(){

    Solution s;
    vector<int> nums = {0,0,0,0};
    s.threeSum(nums);

    return 0;
}