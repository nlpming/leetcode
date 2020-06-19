//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> memo;

/**
 * 记忆化搜索：自顶向下求解
 * @param n
 * @return
 */
int fib1(int n){
    if(n == 0 || n == 1)
        return 1;

    if(memo[n] != -1)
        return memo[n];

    memo[n] = fib1(n-1)+fib1(n-2);
    return memo[n];
}

/**
 * 动态规划：自底向上求解
 * @param n
 * @return
 */
int fib2(int n){
    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 20;
    memo = vector<int>(n+1, -1);

    // 记忆化搜索
    time_t start_time = clock();
    cout<<fib1(n)<<endl;
    time_t end_time = clock();

    cout<<"time: "<<double(end_time-start_time)/CLOCKS_PER_SEC<<"s"<<endl;

    // 动态规划
    start_time = clock();
    cout<<fib2(n)<<endl;
    end_time = clock();

    cout<<"time: "<<double(end_time-start_time)/CLOCKS_PER_SEC<<"s"<<endl;

    return 0;
}