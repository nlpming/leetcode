//
// Created by 陈志明 on 2021/9/1.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        //注意：
        // dp[i]表示偷取[0...i]个房子，所获得的最大金额；

        for(int i = 1; i < n; i++){
            if(i == 1){
                //1. 两个房子，只能从中选个最大的；
                dp[i] = max(nums[0], nums[1]);
            }else{
                //2. 选择偷取nums[i]，或者不偷取nums[i]；
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            }
        }

        return dp[n-1];
    }
};