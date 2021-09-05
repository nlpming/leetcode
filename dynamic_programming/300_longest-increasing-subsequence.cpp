//
// Created by 陈志明 on 2021/9/5.
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        //dp[i]：表示以nums[i]结尾的最长上升子序列；
        vector<int> dp(n, 1);

        //状态转移方程：dp[i] = max{1+dp[j]} j=1...i-1；  if nums[i] > nums[j]
        int res = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }

            if(dp[i] > res)
                res = dp[i];
        }

        return res;
    }
};