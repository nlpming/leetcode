//
// Created by 陈志明 on 2020/5/31.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * 题目描述：0-1背包问题
 * 考点：动态规划
 * 是否做出：否
 * 时间复杂度：O(n * C) 其中n为物品个数; C为背包容积；
 * 空间复杂度：O(n * C)
 */
class Solution{
public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int C){
        // w物品重量；v物品价值；C最大容量；总共有n个物品；
        assert(w.size() == v.size() && C >= 0);
        int n = w.size();
        if(n == 0 || C == 0)
            return 0;

        // 状态定义dp[i][j]：考虑将物品0...i，放进容量为j的背包；
        vector<vector<int>> dp(n, vector<int>(C + 1,0));

        // 将物品0，放入容量为j的背包；
        for(int j = 0 ; j <= C ; j ++)
            dp[0][j] = (j >= w[0] ? v[0] : 0);

        // 状态转移：dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]])
        // 备注：第i个物品是否放入背包中
        for(int i = 1 ; i < n ; i ++)
            for(int j = 0 ; j <= C ; j ++){
                dp[i][j] = dp[i-1][j];
                if(j >= w[i])
                    dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
            }

        return dp[n - 1][C];
    }
};

int main() {
    vector<int> w = {1,2,3};
    vector<int> v = {6,10,12};
    int C = 5;

    cout << Solution().knapsack01(w, v, C) << endl;

    return 0;
}