//
// Created by 陈志明 on 2020/5/21.
//
#include <iostream>
#include <queue>
#include <utility>
#include <stdexcept>

using namespace std;

/**
 * 题目描述：完全平方数
 * 考点：队列、广度优先遍历(无权图的最短路径)
 * 是否做出：否
 */
class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;

        queue<pair<int, int>> q;
        // 记录结点是否被访问过，如果访问过则此时到此结点的路径一定是最短的
        vector<bool> visited(n+1, false);

        // 队列中存储的项：(num, step)
        q.push(make_pair(n, 0));
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            if(num == 0) return step; // 找到最优解

            for(int i = 1; ; i++){
                int data = num-i*i;
                if(data < 0) break;

                if(!visited[data]){
                    // 无权有向图
                    q.push(make_pair(data, step+1));
                    visited[data] = true;
                }
            }
        }
        throw invalid_argument("No Solution.");
    }
};

int main() {
    cout<<Solution().numSquares(13)<<endl;

    return 0;
}