//
// Created by 陈志明 on 2020/5/29.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：完全平方数
 * 考点：广度优先搜索、动态规划
 * 是否做出：是
 */
class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
            return 0;

        vector<int> dp(n+1, 0);
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int min_val = n;
            // min{1+f(n-1), 2^2+f(n-4), .... j^2+f(n-j^2)}；n-j^2大于等于0；
            for(int j = 1; i - j*j >=0; j++){
                min_val = min(min_val, 1+dp[i-j*j]);
            }
            dp[i] = min_val;
        }

        return dp[n];
    }
};

int main() {
    cout << Solution().numSquares(1) << endl;

    return 0;
}