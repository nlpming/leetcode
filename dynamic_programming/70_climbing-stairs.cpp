//
// Created by 陈志明 on 2021/8/31.
//

/*
 * 考点：动态规划；
 * 难度：*
 * */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        //NOTE: 斐波那契数列；
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};