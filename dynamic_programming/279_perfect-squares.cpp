//
// Created by 陈志明 on 2021/8/31.
//

class Solution {
public:
    int numSquares(int n) {
        //解题思路：
        // dp[n] = min{dp[n-1], dp[n-4], ..., dp[n-k^2]} + 1;

        vector<int> dp(n+1, INT_MAX);
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