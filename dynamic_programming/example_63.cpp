//
// Created by 陈志明 on 2020/5/30.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：不同路径II
 * 考点：动态规划
 * 是否做出：是
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // 有障碍物
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else{
                    if(i == 0 && j == 0)
                        dp[i][j] = 1;
                    else if(i == 0){
                        dp[i][j] = dp[i][j-1];
                    }
                    else if(j == 0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> nums = {{0,0,0},{0,1,0},{0,0,0}};
    cout << Solution().uniquePathsWithObstacles(nums) << endl;

    return 0;
}