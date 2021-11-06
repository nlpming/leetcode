//
// Created by 陈志明 on 2021/9/1.
//

/*
 * 考点：动态规划；
 * 难度：***
 * */
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();

        //状态定义：dp[i]表示s[0...i-1]的解法方法有多少个；
        //1. 如果s[i-1]不等于0，则s[i-1]可以单独解码；
        //2. 如果s[i-2,i-1]处于[10, 26]之间，则s[i-2,i-1]可以单独解码；
        //3. 爬楼梯问题的升级版本；

        vector<int> dp(n+1, 0);
        dp[0] = 1; //NOTE: 注意此处；

        for(int i = 1; i <= n; i++){
            if(s[i-1] != '0')
                dp[i] += dp[i-1];

            if(i > 1 && s[i-2] >= '1' && (10*(s[i-2] - '0') + (s[i-1] - '0')) <= 26)
                dp[i] += dp[i-2];
        }

        return dp[n];
    }
};