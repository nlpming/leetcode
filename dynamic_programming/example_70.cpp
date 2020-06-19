//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：爬楼梯
 * 考点：动态规划
 * 是否做出：是
 */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;

        // 相当于求解Fibnacci数列
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main() {
    cout<<Solution().climbStairs(10)<<endl;

    return 0;
}