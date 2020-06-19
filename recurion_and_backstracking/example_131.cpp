//
// Created by 陈志明 on 2020/5/27.
//
#include <iostream>
#include <vector>
#include <string>
#include "print.h"

using namespace std;

/**
 * 题目描述：分割回文串
 * 考点：回溯算法
 * 是否做出：是
 */
class Solution {
private:
    bool isPalindrome(string s){
        int i = 0, j = s.size()-1;
        while(i <= j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void findPalindrome(string s, int left, int right, vector<string> p, vector<vector<string>>& res){
        if(left > right){
            res.push_back(p);
            return;
        }

        // 从left开始，截取长度为1,2,3,...的子串进行验证，成功则用剩余部分递归
        for(int i = 1; i <= right-left+1; i++){
            if(isPalindrome(s.substr(left, i))){
                p.push_back(s.substr(left, i));
                findPalindrome(s, left+i, right, p, res);
                p.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> p;
        vector<vector<string>> res;

        findPalindrome(s, 0, s.size()-1, p, res);
        return res;
    }
};

int main() {
    string s = "aab";
    vector<vector<string>> res = Solution().partition(s);

    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);

    return 0;
}