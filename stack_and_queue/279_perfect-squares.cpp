//
// Created by 陈志明 on 2021/8/27.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * 考点：广度优先搜索 + 动态规划
 * 难度：***
 * */
class Solution {
public:

    //方法一：广度优先搜索 + 队列 【最短路径】
    int numSquares_one(int n) {
        queue<pair<int, int>> record;
        vector<bool> visited(n, false); //NOTE: 用于记录元素是否被访问；【注意此处容易忽略】

        record.push(make_pair(0, n));
        visited[n-1] = true;
        while(!record.empty()){
            int level = record.front().first;
            int data = record.front().second;
            record.pop();

            //NOTE: 找到最短路径；
            if(data == 0){
                return level;
            }

            //NOTE: 压入数据；data - i*i
            for(int i = 1; i*i <= data; i++){
                int val = data - i*i;
                if(!visited[val]){
                    record.push(make_pair(level+1, val));
                    visited[val] = true;
                }
            }
        }

        return n;
    }

    //方法二：动态规划；
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j*j <= i; j++){ //NOTE: 注意j*j == x的情况，比如i = 9;
                dp[i] = min(dp[i], dp[i - j*j]+1);
            }
        }

        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.numSquares(12) << endl;

    return 0;
}



