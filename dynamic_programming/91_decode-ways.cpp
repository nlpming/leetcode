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

        int tmp;
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