//
// Created by 陈志明 on 2021/9/5.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

/*
 * 考点：动态规划；背包问题；
 * 难度：**
 * */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        //先遍历物品，表示可以使用几个物品；
        for(int i = 0; i < coins.size(); i++){ //遍历物品；
            for(int c = coins[i]; c <= amount; c++){ //遍历背包；
                dp[c] = min(dp[c], dp[c - coins[i]]+1);
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,2,5};

    cout << s.coinChange(coins, 11) << endl;

    return 0;
}


