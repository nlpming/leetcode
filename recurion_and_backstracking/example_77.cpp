//
// Created by 陈志明 on 2020/5/27.
//
#include <iostream>
#include <vector>
#include <set>
#include "print.h"

using namespace std;

/**
 * 题目描述：组合问题
 * 考点：回溯算法
 * 是否做出：是
 */
class Solution {
private:
    vector<vector<int>> res;

    void generateCombination(int n, int k, int index, vector<int> p){
        if(p.size() == k){
            res.push_back(p);
            return;
        }

        // 此处可以做剪枝：还有k - p.size()个空位；
        // i的取值最多为 n - (k - p.size()) + 1
        for(int i = index; i <= n-(k-p.size())+1; i++){
            p.push_back(i);
            generateCombination(n, k, i+1, p);
            p.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n)
            return res;

        vector<int> p;
        generateCombination(n, k, 1, p);

        return res;
    }
};

int main() {
    vector<vector<int>> res = Solution().combine(4,2);
    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);

    return 0;
}