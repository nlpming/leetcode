//
// Created by 陈志明 on 2020/5/30.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：解码方法
 * 考点：动态规划
 * 是否做出：否
 */
class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if(length == 0) return 0;
        if(s[0] == '0') return 0;

        // 爬楼梯的升级版：dp[i+1] = dp[i] + dp[i-1]
        // 1. s[i] = 0, dp[i+1] = dp[i-1]
        // 2. s[i-1,i]符合条件（1<=x<=26）：dp[i+1] = dp[i] + dp[i-1]
        vector<int> dp(length+1, 0);
        dp[0] = 1;

        for(int i = 0; i < length; i++){
            // s[i]=0的情况
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            // s[i-1]=1 && (s[i-1]=2 && s[i]<=6)
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))){
                dp[i+1] += dp[i-1];
            }
        }

        return dp[length];
    }
};

int main() {
    string s = "101";
    cout << Solution().numDecodings(s) << endl;

    return 0;
}