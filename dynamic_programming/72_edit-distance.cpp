//
// Created by 陈志明 on 2021/9/5.
//

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        //状态定义：dp[i][j]表示将 word1[0...i-1] 编辑成 word2[0...j-1] 的最小编辑距离；【答案返回：dp[m][n]】
        //1. 如果word1[i-1] == word2[j-1]，则dp[i][j] = dp[i-1][j-1];
        //2. 否则：dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        //3. （1）dp[i-1][j] 需要删除word1[i-1]; （2）dp[i][j-1] 需要插入word2[j-1]；（3）需要替换word1[i-1], word2[j-1]；

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            dp[i][0] = dp[i-1][0] + 1;
        }
        for(int j = 1; j <= n; j++){
            dp[0][j] = dp[0][j-1] + 1;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }

        return dp[m][n];
    }
};