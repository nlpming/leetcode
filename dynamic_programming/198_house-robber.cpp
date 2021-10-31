//
// Created by 陈志明 on 2021/9/1.
//

/*
 * 考点：动态规划；
 * 难度：*
 * */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        //注意：
        // dp[i]表示偷取nums[0...i]个房子，所获得的最大金额；
        for(int i = 1; i < n; i++){
            if(i == 1){
                dp[i] = max(nums[0], nums[1]);
            }else{
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            }
        }

        return dp[n-1];
    }
};