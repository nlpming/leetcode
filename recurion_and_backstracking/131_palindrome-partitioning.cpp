//
// Created by 陈志明 on 2021/8/29.
//
#include <iostream>
#include <string>
#include <vector>
#include "print.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool isValid(string s){
        //判断是否回文串；
        if(s.size() == 0)
            return true;

        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(string s, int segStart, vector<string>& segments){
        //找到问题答案；
        if(segStart == s.size()){
            res.push_back(segments);
            return;
        }

        //尝试截取长度len=1,2,3,...进行判断；
        for(int len = 1; segStart+len <= s.size(); len++){
            string tmp = s.substr(segStart, len);
            if(tmp.size() > 0 && isValid(tmp)){ //判断截取字符串是否有效；
                segments.push_back(tmp);
                dfs(s, segStart+tmp.size(), segments);
                segments.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if(s.size() == 0)
            return res;

        vector<string> segments;
        dfs(s, 0, segments);
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<string>> res = s.partition("aab");

    for(int i = 0; i < res.size(); i++){
        printVector(res[i]);
    }

    return 0;
}