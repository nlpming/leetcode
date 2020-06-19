//
// Created by 陈志明 on 2020/5/9.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：长度最小的子数组
 * 考点：数组、双指针
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 注意空数组的情况
        if(nums.size() == 0)
            return 0;

        int left=0, right=0;
        int sum_val=nums[0];
        int min_val=nums.size()+1; // 注意min_val初始化为nums.size()+1

        // 滑动窗口：先移动right，然后移动left
        while(right < nums.size()){
            if(sum_val < s){
                right++;
                if(right < nums.size())
                    sum_val += nums[right];
            }
            else{
                if(right-left+1 < min_val)
                    min_val = right-left+1;

                sum_val -= nums[left];
                left++;
            }
        }

        if(min_val == nums.size()+1)
            return 0;
        else
            return min_val;
    }
};

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;

    cout<<Solution().minSubArrayLen(target, nums)<<endl;
    return 0;
}


