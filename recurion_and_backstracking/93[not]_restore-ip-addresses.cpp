//
// Created by 陈志明 on 2021/8/29.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

/*
 * 考点：回溯算法；
 * 难度：****
 * */
class Solution{
private:
    const int SEG_COUNT = 4;
    vector<string> res;
    vector<int> segments;

public:
    //NOTE: segIdx -> 表示分段数字总数；segStart -> 表示开始切分的位置；
    void dfs(string s, int segIdx, int segStart){
        //找到问题答案；
        if(segIdx == SEG_COUNT && segStart == s.size()){
            string tmp;
            for(int i = 0; i < segments.size(); i++){
                if(i != segments.size()-1){
                    tmp += to_string(segments[i]) + ".";
                }else{
                    tmp += to_string(segments[i]);
                }
            }

            res.push_back(tmp);
            return;
        }

        //1. 未找到4个片段，已经遍历到s的末尾；2. 或者已找到四个片段，没有遍历完s；
        if(segStart == s.size() || segIdx == SEG_COUNT){
            return;
        }

        //3. 当前字符为0的情况；
        if(s[segStart] == '0'){
            segments[segIdx] = 0;
            dfs(s, segIdx+1, segStart+1);
            return;
        }

        int addr = 0;
        for(int i = segStart; i < s.size(); i++){
            addr = addr*10 + (s[i] - '0'); //NOTE: addr, segments用于回溯；
            if(addr > 0 && addr <= 255){
                segments[segIdx] = addr;
                dfs(s, segIdx+1, i+1);
            }else{ //addr范围不在[0,255]范围；
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() == 0)
            return res;

        segments.resize(SEG_COUNT); //NOTE: 注意此处不能省略；
        dfs(s, 0, 0);
        return res;
    }
};

int main(){

    Solution s;
    printVector(s.restoreIpAddresses("0000"));

    return 0;
}






