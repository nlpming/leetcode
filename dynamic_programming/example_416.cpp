//
// Created by 陈志明 on 2020/6/2.
//
#include <iostream>
#include <vector>

using namespace std;

/*
 * 题目描述：分割等和子集
 * 考点：动态规划、0-1背包问题
 * 是否做出：否
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        // 和必须为偶数
        if(sum%2 != 0) return false;

        int C = sum/2;
        // 状态定义dp[i][j]: 表示使用0...i物品，能否填满容量为j的背包；
        vector<vector<bool>> dp(n, vector<bool>(C+1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= C; j++){
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n-1][C];
    }
};

int main() {
    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition(nums) << endl;

    return 0;
}