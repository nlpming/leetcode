//
// Created by 陈志明 on 2020/5/10.
//
#include <iostream>
#include <vector>
#include <string>
#include "print.h"
using namespace std;

/**
 * 题目描述：找到字符串中所有字母异位词
 * 考点：数组、滑动窗口
 * 是否做出：否
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 特殊情况的处理
        if(s.size() < p.size())
            return {};

        // 初始化滑动窗口
        int left=0, right=-1;
        // freq_s 记录滑动窗口中的字符序列出现次数
        vector<int> freq_s(26, 0), freq_p(26, 0), res; // NOTE: vector的初始化操作

        // 初始化代码值
        for(int i=0; i<p.size(); i++){
            freq_p[p[i] - 'a']++;
            freq_s[s[++right] - 'a']++;
        }

        if (freq_s == freq_p) // NOTE: 两个vector可以直接进行比较
            res.push_back(left);

        // 固定长度的滑动窗口
        while(right < s.size()-1){
            freq_s[s[++right] - 'a']++;
            freq_s[s[left++] - 'a']--;
            if (freq_s == freq_p)
                res.push_back(left);
        }
        return res;
    }
};

int main(){
    string s="cbaebabacd";
    string p="abc";

    vector<int> res;
    res = Solution().findAnagrams(s, p);
    printVector(res);

    return 0;
}