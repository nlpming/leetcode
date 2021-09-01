//
// Created by 陈志明 on 2021/9/1.
//

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;

        int n = s.size();
        //dp[i]：表示s[0...i]的解码方法；
        vector<int> dp(n, 0);

        //NOTE: i == 0的处理；
        if(s[0] == '0') dp[0] = 0;
        else dp[0] = 1;

        for(int i = 1; i < n; i++){
            //1.当前字符可以单独解码；
            if(s[i] != '0'){
                dp[i] += dp[i-1];
            }

            //2.s[i-1,i]可以单独解码；
            if(s[i-1] != '0' && (10*(s[i-1] - '0') + (s[i] - '0')) <= 26){
                //NOTE: i == 1的特殊处理；
                if(i == 1)
                    dp[i] += 1;
                else
                    dp[i] += dp[i-2];
            }
        }

        return dp[n-1];
    }
};