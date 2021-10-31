//
// Created by 陈志明 on 2021/8/31.
//

/*
 * 考点：动态规划；
 * 难度：*
 * */
class Solution {
public:
    //方法一：空间复杂度O(mn)
    int minPathSum_one(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        //NOTE: i,j为0时候的初始化
        for(int j = 1; j < n; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }

    //方法二：空间复杂度O(n)
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;

        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[j] = grid[i][j];
                }else if(i == 0){
                    dp[j] = dp[j-1] + grid[i][j];
                }else if(j == 0){
                    dp[j] = dp[j] + grid[i][j];
                }else{
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }
            }
        }

        return dp[n-1];
    }
};