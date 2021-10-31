//
// Created by 陈志明 on 2021/9/5.
//

/*
 * 考点：动态规划；背包问题；
 * 难度：***
 * */
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        //背包问题：挑出物品，填满sum/2的背包；
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];

        //不能被平分；
        if(sum%2 != 0)
            return false;

        int C = sum/2;
        vector<bool> dp(C+1, false);

        for(int i = 0; i < nums.size(); i++){ //遍历物品；
            for(int c = C; c >= nums[i]; c--){ //遍历背包；【逆序】
                if(i == 0 && nums[i] == c)
                    dp[c] = true;
                else
                    dp[c] = dp[c] || dp[c - nums[i]]; //放入nums[i]，和不放入nums[i]；
            }
        }

        return dp[C];
    }
};