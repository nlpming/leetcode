//
// Created by 陈志明 on 2021/9/5.
//

/*
 * 考点：动态规划；
 * 难度：**
 * */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        //dp[i][j]表示字符子串text1[0...i-1], text2[0...j-1]的最长公共子序列；
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        //dp[0][j] -> 表示text1为空的情况；dp[i][0] -> 表示text2为空的情况；
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};