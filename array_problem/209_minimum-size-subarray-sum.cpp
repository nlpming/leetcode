//
// Created by 陈志明 on 2021/8/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * 考点：滑动窗口指针；
 * 难度：**
 * */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = -1, right = 0;
        int sum_val = nums[0], min_len = nums.size()+1;

        //注意：
        // 1. sum_val记录连续子数组 (left...right] 的元素之和；
        // 2. 初始化left = -1, right = 0；sum_val = nums[0]
        // 3. 更新min_len的时候，一定得注意满足两个条件：right-left < min_len && sum_val >= target；

        while(left < right){ //NOTE: 注意循环终止条件；
            if(sum_val < target && right+1 < nums.size()) {
                right++;
                sum_val += nums[right];
            }else{
                if(right-left < min_len && sum_val >= target){ //NOTE: 注意此处的条件；
                    min_len = right-left;
                }

                left++;
                sum_val -= nums[left];
            }
        }

        return min_len == nums.size()+1 ? 0 : min_len;
    }
};


int main(){

    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout << s.minSubArrayLen(target, nums) << endl;


    return 0;
}