//
// Created by 陈志明 on 2020/5/27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

/**
 * 题目描述：组合总和
 * 考点：数组、回溯算法
 * 是否做出：是
 */
class Solution {
private:
    vector<vector<int>> res;
    void findCombination(vector<int> candidates, int target, int start, vector<int> p){
        if(target < 0)
            return;

        if(target == 0){
            res.push_back(p);
            return;
        }

        // 注意开始递归的位置
        for(int i = start; i < candidates.size(); i++){
            p.push_back(candidates[i]);
            findCombination(candidates, target-candidates[i], i, p);
            p.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return res;

        sort(candidates.begin(), candidates.end());
        vector<int> p;

        findCombination(candidates, target, 0, p);
        return res;
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);

    return 0;
}