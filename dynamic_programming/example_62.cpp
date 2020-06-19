//
// Created by 陈志明 on 2020/5/30.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：不同路径
 * 考点：动态规划
 * 是否做出：是
 * 解法一：时间复杂度O(m*n)，空间复杂度O(m*n)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    cout << Solution().uniquePaths(3, 4);

    return 0;
}