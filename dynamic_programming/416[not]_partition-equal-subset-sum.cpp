//
// Created by 陈志明 on 2021/9/5.
//

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        //解题思路：
        //1. 首先判断，数组是否可以被平分；
        //2. 然后处理将一个物品，是否能够恰好装入sum/2大小的背包中；
        //3. 然后 c -> (C, 0) ，逐行填满dp[c]；
        //4. 状态转移方程：F(n,C) = F(n-1,C) || F(n-1, C-w(i))

        //不能被平分；
        if(sum%2 != 0)
            return false;

        int n = nums.size();
        int C = sum/2;
        vector<bool> dp(C+1, false);

        //1.处理i=0;
        for(int c = 0; c <= C; c++){
            dp[c] = (nums[0] == c);
        }

        //2.将n个物品填满sum/2大小的背吧；
        for(int i = 1; i < n; i++){
            for(int c = C; c >= nums[i]; c--){
                dp[c] = dp[c] || dp[c - nums[i]]; //NOTE: 不使用nums[i] & 使用nums[i]；
            }
        }

        return dp[C];
    }
};