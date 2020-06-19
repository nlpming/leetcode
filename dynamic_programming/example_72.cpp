//
// Created by 陈志明 on 2020/5/30.
//
/**
 * 参考：https://zhuanlan.zhihu.com/p/43009353
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：最小编辑距离
 * 考点：动态规划
 * 是否做出：是
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // word1或者word2为空的情况
        if(m == 0) return n;
        if(n == 0) return m;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m+1; i++){
            for(int j = 0; j < n+1; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = 0;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] + 1; // 一次插入操作
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] + 1; // 一次删除操作
                else{
                    // 删除，插入操作
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                    // 替换操作，判断word1[i-1]与word2[j-1]是否相等
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 0);
                    else
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    string word1 = "horse", word2 = "ros";
    cout << Solution().minDistance(word1, word2) << endl;

    return 0;
}