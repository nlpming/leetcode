//
// Created by 陈志明 on 2021/8/31.
//

class Solution {
public:
    //方法一：空间复杂度O(m*n)
    int minimumTotal_one(vector <vector<int>> &triangle) {
        if (triangle.size() == 0)
            return 0;

        int m = triangle.size(), n = triangle[m - 1].size();
        vector <vector<int>> dp(m, vector(n, 0));
        dp[0][0] = triangle[0][0];

        //NOTE：注意每一列元素个数不一样；
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (i == j) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
            }
        }

        int minValue = INT_MAX;
        for (int j = 0; j < n; j++) {
            minValue = min(minValue, dp[m - 1][j]);
        }

        return minValue;
    }

    //方法二：空间复杂度O(n);
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;

        //NOTE: 注意n的初始化；
        int m = triangle.size(), n = triangle[m-1].size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];

        for(int i = 1; i < m; i++){
            //NOTE: 注意此处，从后往前求值；
            for(int j = triangle[i].size()-1; j >= 0; j--){
                if(j == 0){
                    dp[j] = dp[j] + triangle[i][j];
                }else if(i == j){
                    dp[j] = dp[j-1] + triangle[i][j];
                }else{
                    dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
                }
            }
        }

        int minValue = INT_MAX;
        for(int i = 0; i < n; i++){
            minValue = min(minValue, dp[i]);
        }
        return minValue;
    }
}