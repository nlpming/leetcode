//
// Created by 陈志明 on 2021/9/5.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, amount+2);

        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){ // 遍历物品
            for(int j = coins[i]; j <= amount; j++){ // 遍历背包
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }

        if(dp[amount] == amount+2)
            return -1;
        return dp[amount];
    }
};

int main(){
    Solution s;
    vector<int> coins = {1,2,5};

    cout << s.coinChange(coins, 11) << endl;

    return 0;
}


