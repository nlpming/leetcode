//
// Created by 陈志明 on 2020/6/8.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：不同路径
 * 考点：动态规划
 * 是否做出：是
 * 解法一：时间复杂度O(n)，空间复杂度O(m*n)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        // 注意i,j初始取值
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] = dp[j-1] + dp[j];
            }
        }

        return dp[n-1];
    }
};

int main() {
    cout << Solution().uniquePaths(3, 4);

    return 0;
}


