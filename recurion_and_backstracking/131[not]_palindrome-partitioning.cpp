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
    bool isValid(string str){
        if(str.size() == 0)
            return true;

        int i = 0;
        int j = str.size()-1;
        while(i < j){
            if(str[i] == str[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }

        return true;
    }

    void dfs(string s, int segStart, vector<string>& segments){
        //1.找到问题答案；
        if(segStart == s.size()){
            res.push_back(segments);
            return;
        }

        //2. 从segStart位置开始，每次截取长度：1->2->3->... 子串进行判断；
        for(int j = 1; segStart+j <= s.size(); j++){
            string str = s.substr(segStart, j);
            if(str.size() > 0 && isValid(str)){
                segments.push_back(str);

                //3. 下一个分割位置是：segStart + str.size();
                dfs(s, segStart+str.size(), segments);
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