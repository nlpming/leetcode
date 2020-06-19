//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <vector>
#include <string>
#include "print.h"

using namespace std;

/**
 * 题目描述：N皇后问题
 * 考点：回溯
 * 是否做出：否
 */
class Solution {
private:
    vector<bool> col, dia1, dia2;
    vector<vector<string>> res;

    void putQueen(int n, int index, vector<int> temp) {
        if(index == n){
            res.push_back(generateOutput(n, temp));
            return;
        }

        // 在第i列摆放第index行的皇后
        for(int i = 0; i < n; i++){
            // 判断列、两个方向对角线是否被占用；dia1左下对角线；dia2右下对角线
            if(!col[i] && !dia1[i+index] && !dia2[index-i+n-1]){
                temp.push_back(i);
                col[i] = true;
                dia1[i+index] = true;
                dia2[index-i+n-1] = true;

                putQueen(n, index+1, temp);
                col[i] = false;
                dia1[i+index] = false;
                dia2[index-i+n-1] = false;
                temp.pop_back();
            }
        }
    }

    vector<string> generateOutput(int n, vector<int> temp){
        // 字符串数组初始化方式
        vector<string> result(n, string(n, '.'));

        for(int i = 0; i < result.size(); i++){
            result[i][temp[i]] = 'Q';
        }
        return result;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // 注意数组初始化方式，col列是否被占用
        for(int i = 0; i < n; i++)
            col.push_back(false);

        // 两条对角线是否被占用
        for(int i = 0; i < 2*n-1; i++){
            dia1.push_back(false);
            dia2.push_back(false);
        }

        vector<int> temp;
        putQueen(n, 0, temp);
        return res;
    }
};

int main() {
    vector<vector<string>> res = Solution().solveNQueens(5);

    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);

    return 0;
}