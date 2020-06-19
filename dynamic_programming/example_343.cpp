//
// Created by 陈志明 on 2020/5/29.
//
#include <iostream>
#include <vector>
#include <cassert>
#include "print.h"

using namespace std;

/**
 * 题目描述：整数拆分
 * 考点：动态规划
 * 是否做出：是
 */
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        assert(n >= 2);

        // min{1*(i-1), 2*(i-2), ..., j*(i-j)}
        for(int i = 2; i <= n; i++){
            int max_val = 1;
            for(int j = 1; j < i; j++){
                if(j <= i-j){
                    // dp[i-j]代表对i-j继续分割的最优值；(i-j)*j表示将数字i分割成i-j和j；
                    int res = max(dp[i-j]*j, (i-j)*j);
                    max_val = max(max_val, res);
                }
                else
                    break;
            }
            dp[i] = max_val;
        }

        return dp[n];
    }
};

int main() {
    cout<<Solution().integerBreak(10)<<endl;

    return 0;
}