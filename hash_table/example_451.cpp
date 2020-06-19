//
// Created by 陈志明 on 2020/5/12.
//
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include "print.h"

using namespace std;

/**
 * 题目描述：根据字符出现频率排序
 * 考点：哈希表
 * 是否做出：是
 */
class Solution {
public:
    static bool compareValue(const pair<char, int>& p1, const pair<char, int>& p2){
        return p1.second > p2.second;
    }

    string frequencySort(string s) {
        map<char, int> char_freq;
        vector<pair<char,int>> char_freq_vec;

        // char及其出现的频率
        for(int i=0; i<s.size(); i++){
            if(char_freq.find(s[i]) == char_freq.end())
                char_freq[s[i]] = 1;
            else
                char_freq[s[i]]++;
        }

        // NOTE: C++中没有对map value进行排序的函数，先转成vector
        for(map<char,int>::iterator it=char_freq.begin(); it!=char_freq.end(); ++it){
            char_freq_vec.push_back(make_pair(it->first, it->second));
        }
        sort(char_freq_vec.begin(), char_freq_vec.end(), compareValue);

        // 构建字符串
        string res="";
        for(int i=0; i<char_freq_vec.size(); i++){
            char ch = char_freq_vec[i].first;
            int freq = char_freq_vec[i].second;
            string tmp(freq, ch); // 注意字符串初始化方式

            res += tmp;
        }
        return res;
    }
};


int main(){
    string s="Aabb";
    cout<<Solution().frequencySort(s)<<endl;

    return 0;
}
