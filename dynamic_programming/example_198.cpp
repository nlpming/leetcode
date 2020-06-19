//
// Created by 陈志明 on 2020/5/31.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：打家劫舍
 * 考点：动态规划
 * 是否做出：否
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        if(length == 1)
            return nums[0];

        // 状态定义dp[i]：表示偷取nums[0...i]所获得最大价值
        vector<int> dp(length, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // 状态转移方程：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        for(int i = 2; i < length; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

        return dp[length-1];
    }
};

int main() {
    vector<int> nums ={1,2,3,1};
    cout << Solution().rob(nums) << endl;

    return 0;
}