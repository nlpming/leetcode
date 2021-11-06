//
// Created by 陈志明 on 2021/9/1.
//

/*
 * 考点：动态规划；
 * 难度：**
 * */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() <= 0) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        //对第一行，第一列特殊处理；
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] == 1 || dp[i-1][0] == 0) //NOTE: 注意此处，如果前面为0；则后面肯定走不到；
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
        }

        for(int j = 1; j < n; j++){
            if(obstacleGrid[0][j] == 1 || dp[0][j-1] == 0)
                dp[0][j] = 0;
            else
                dp[0][j] = 1;
        }


        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};