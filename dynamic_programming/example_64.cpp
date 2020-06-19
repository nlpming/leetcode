//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：最小路径和
 * 考点：动态规划
 * 是否做出：是
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        // 二维数组的初始化
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<Solution().minPathSum(grid);

    return 0;
}