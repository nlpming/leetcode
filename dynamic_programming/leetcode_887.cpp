//
// Created by 陈志明 on 2020/6/21.
//
#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

void print(vector<vector<int>> res){
    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);
}

class Solution {
public:
    int superEggDrop(int K, int N) {
        // 初始化 dp[0][k] = 0, dp的大小为：[N+1, K+1]
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

        // 初始化 dp[i][1] = i
        for(int i = 0; i <= N; i++)
            dp[i][1] = i;

        for(int i = 1; i <= N; i++) {
            for(int k = 2; k <= K; k++) {
                int res = N;
                for(int j = 1; j <= i; j++) {
                    res = min(res , max(dp[j-1][k-1], dp[i-j][k]) + 1);
                }

                dp[i][k] = res;
            }
        }

        return dp[N][K];
    }
};


int main(){
    int K = 2, N = 100;

    cout << Solution().superEggDrop(K, N) << endl;

    return 0;
}


