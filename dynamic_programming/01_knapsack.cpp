//
// Created by 陈志明 on 2021/9/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int Example(vector<int> w, vector<int> v, int C){

        //0-1背包问题，解题思路：
        //1. w表示物品的重量；
        //2. v表示每个物品的价值；
        //3. C表示背包的容积（重量最大值）；

        int n = w.size();
        vector<vector<int>> dp(n, vector<int>(C+1, 0));

        for(int c = 0; c <= C; c++){
            for(int i = 0; i < n; i++){
                if(c == 0){ //1. 容量为0的情况；
                    dp[i][c] = 0;
                }else if(i == 0){ //2. 物品为一个的情况，判断c是否大于w[i]；
                    if(c - w[i] >= 0){
                        dp[i][c] = v[i];
                    }
                }else{ //3. dp[i][c] = max(dp[i-1][c], v[i]+ dp[i-1][c-w(i)]
                    dp[i][c] = dp[i-1][c];
                    if(c - w[i] >= 0){
                        dp[i][c] = max(dp[i][c], v[i] + dp[i-1][c - w[i]]);
                    }
                }
            }
        }

        return dp[n-1][C];
    }
};

int main(){

    Solution s;
    cout << s.Example({1,2,3}, {6,10,12}, 5) << endl;

    return 0;
}