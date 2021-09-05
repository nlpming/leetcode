//
// Created by 陈志明 on 2021/9/5.
//

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        //dp[i][j]表示字符子串word1[0...i-1]，word2[0...j-1]的最小编辑距离；
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }

        for(int j = 0; j <= n; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                //替换：需要判断当前字符 word1[i-1], word2[j-1]是否相等；相等则不需要替换这两个字符；
                dp[i][j] = (word1[i-1] == word2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1);
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); //多余需要 删除word1[i-1]
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); //缺少需要 插入word2[j-1]
            }
        }

        return dp[m][n];
    }
};