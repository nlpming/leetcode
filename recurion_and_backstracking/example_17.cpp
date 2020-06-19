//
// Created by 陈志明 on 2020/5/26.
//
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "print.h"

using namespace std;

/**
 * 题目描述：电话号码的字母组合
 * 考点：字符串、回溯算法
 * 是否做出：是
 */
class Solution {
private:
    // 注意字符串数组如何定义
    const string letterMap[10] = {" ", "", "abc", "def", "ghi", "jkl",
                             "mno", "pqrs", "tuv", "wxyz"};
public:
    void findCombinations(const string& digits, int index, string p, vector<string>& res){
        // index：表示当前处理第几个数字
        // p：表示当前生成的字母字符串
        if(index == digits.size()){
            res.push_back(p);
            return;
        }

        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c-'0'];

        for(int i = 0; i < letters.size(); i++){
            p.push_back(letters[i]);
            findCombinations(digits, index+1, p, res);
            p.pop_back(); // 回溯过程
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;

        findCombinations(digits, 0, "", res);
        return res;
    }
};


int main() {
    string digits = "245";
    printVector(Solution().letterCombinations(digits));

    return 0;
}