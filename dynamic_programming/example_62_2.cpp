//
// Created by 陈志明 on 2020/6/8.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目描述：不同路径
 * 考点：动态规划
 * 是否做出：是
 * 解法三：时间复杂度O(n)，空间复杂度O(1)；不同路径：C(m+n-2, m-1) = （m+n-2)!/ [(m-1)!*(n-1)!]
 * C(n, k) = n!/[(n-k)! * k!]
 */
class Solution {
private:
    int process(int n){
        int sum = 1;
        while(n){
            sum *= n;
            n--;
        }
        return sum;
    }
public:
    int uniquePaths(int m, int n) {
        return process(m+n-2) / (process(m-1) * process(n-1));
    }
};

int main() {
    cout << Solution().uniquePaths(3, 4);

    return 0;
}

