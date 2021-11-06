//
// Created by 陈志明 on 2021/8/31.
//

/*
 * 考点：动态规划；
 * 难度：***
 * */
class Solution {
public:
    int integerBreak(int n) {

        //dp[i]表示正整数i，拆分后获得的最大乘积；
        vector<int> dp(n+1, 0);
        dp[1] = 0;

        int res = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                res = max(j*dp[i - j], j*(i-j)); //dp[i - j]可以拆分，也可以不拆分；
                dp[i] = max(dp[i], res);
            }
        }

        return dp[n];
    }
};