//
// Created by 陈志明 on 2021/9/1.
//

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //解析思路: 注意下面的条件；
        //1. obstacleGrid[i][j] == 1，则dp[i][j] = 0;
        //2. i == 0 && j == 0的情况：dp[i][j] = 1;
        //3. i == 0 的情况：dp[i][j] = dp[i][j-1];
        //4. j == 0 的情况：dp[i][j] = dp[i-1][j];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    if(i == 0 && j == 0)
                        dp[i][j] = 1;
                    else if(i == 0)
                        dp[i][j] = dp[i][j-1];
                    else if(j == 0)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};