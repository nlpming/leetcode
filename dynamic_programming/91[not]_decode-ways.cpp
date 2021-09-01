//
// Created by 陈志明 on 2021/9/1.
//

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;

        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        //解题思路：
        //1. 状态定义dp[i]：表示前i个字符 s[0...i-1] 的解码方法；【注意此处状态定义】
        //2. 如果s[i-1] ！= '0'，则s[i-1]可以解码成某个字母(1-9, A-I)；前面i-1个字符的解码方法为dp[i-1]，则 dp[i] += dp[i-1];
        //3. 如果s[i-2] != '0'，并且s[i-2,i-1]构成的数字<=26，则s[i-2,i-1]可以解码成(10-26, J-Z)；则 dp[i] += dp[i-2];

        for(int i = 1; i <= n; i++){
            if(s[i-1] != '0'){
                dp[i] += dp[i-1];
            }

            if(i > 1 && s[i-2] != '0' && (10*(s[i-2]-'0') + (s[i-1] - '0')) <= 26){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};