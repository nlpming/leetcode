//
// Created by 陈志明 on 2021/9/1.
//

/*
 * 考点：动态规划；（注意不同的解法，从时间复杂度和空间复杂度考虑）
 * 难度：**
 * */
class Solution {
public:
    //方法一：时间复杂度O(mn)，空间复杂度O(mn)
    int uniquePaths_one(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //j=0的时候
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }

        //i=0的时候；
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }

    //方法二：时间复杂度O(mn)，空间复杂度O(n)；
    int uniquePaths_two(int m, int n) {
        vector<int> dp(n, 1);

        //NOTE: i，j都从1开始遍历；
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }

    //方法三：从左上角到右下角的过程中，我们需要移动 m+n-2 次，其中有 m-1次向下移动，n-1次向右移动。
    // 因此路径的总数，就等于从 m+n-2次移动中选择 m-1次向下移动的方案数；
    //NOTE: C(m-1, m+n-2) = (m+n-2)!/(m-1)!(n-1)! = (m+n-2)(m+n-3)...n/(m-1)! 【组合问题】
    int uniquePaths(int m, int n) {
        long res = 1;
        for(int x = n, y = 1; y < m; x++,y++){
            res = res * x/y; //NOTE: 注意此处；
        }

        return res;
    }
};