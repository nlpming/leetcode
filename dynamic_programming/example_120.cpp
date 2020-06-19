//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：三角形最小路径和
 * 考点：动态规划
 * 是否做出：是
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;

        // 初始化dp数组
        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(vector<int>(triangle[i].size(), 0));
        }

        // 从上至下遍历数组
        for(int i = 0; i < triangle.size(); i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(i == 0)
                    dp[i][j] = triangle[i][j];
                else{
                    if(j == 0)
                        dp[i][j] = dp[i-1][j] + triangle[i][j];
                    else if(i == j)
                        dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                    else{
                        dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                    }
                }
            }
        }

        // 找到最小值：min_element
        int length = dp.size();
        vector<int>::iterator it = min_element(dp[length-1].begin(),
                dp[length-1].end());
        return *it;
    }
};

int main() {
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<Solution().minimumTotal(triangle);

    return 0;
}