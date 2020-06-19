//
// Created by 陈志明 on 2020/5/30.
//
#include <iostream>
#include <vector>
#include <string>
#include "print.h"

using namespace std;

/**
 * dfs超时
 */
class Solution {
private:
    vector<vector<string>> res;
    void findDecoding(string s, int left, int right, vector<string> temp){
        if(left > right){
            res.push_back(temp);
            return;
        }

        for(int i = 1; i <= right-left+1; i++){
            if(i >= 1 && i <= 2){
                string sub_s = s.substr(left, i);
                if(stoi(sub_s) <= 26 && stoi(sub_s) > 0 && sub_s[0] != '0'){
                    temp.push_back(sub_s);
                    findDecoding(s, left+i, right, temp);
                    temp.pop_back();
                }
            }
        }
    }
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;

        vector<string> temp;
        findDecoding(s, 0, s.size()-1, temp);

        for(int i = 0; i < res.size(); i++)
            printVector(res[i]);

        return res.size();
    }
};

int main() {
    string s = "01";
    cout << Solution().numDecodings(s) << endl;

    return 0;
}