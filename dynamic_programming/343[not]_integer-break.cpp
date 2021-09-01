//
// Created by 陈志明 on 2021/8/31.
//

class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;

        //解题思路：
        //1. 当i-j拆分的时候：dp[i] = min{dp[i-j]*j, j = 1...i-1}
        //2. 当i-j不拆分的时候：dp[i] = min{(i-j)*j, j = 1...i-1}

        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], dp[i-j]*j);
                dp[i] = max(dp[i], (i-j)*j);
            }
        }

        return dp[n];
    }
};