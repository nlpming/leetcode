//
// Created by 陈志明 on 2021/8/31.
//

/*
 * 考点：动态规划、广度优先搜索；
 * 难度：***
 * */
class Solution {
public:
    //方法一：动态规划；
    int numSquares(int n) {
        if(n == 1) return 1;

        //状态转移方程：dp[i] = min{dp[n-1], dp[n-4], dp[n-9], ..., dp[n-k^2]} + 1
        //注意终止：n - k^2 >= 0；

        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }

        return dp[n];
    }
};