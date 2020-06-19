//
// Created by 陈志明 on 2020/5/11.
//
#include <iostream>
#include <string>
#include <map>
#include "print.h"
using namespace std;

/**
 * 题目描述：有效的字母异位词
 * 考点：数组、哈希表
 * 是否做出：是
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> char_freq;

        // char_freq: s中字母及其对应的频率
        for(int i=0; i<s.size(); i++){
            if(char_freq.find(s[i]) == char_freq.end())
                char_freq[s[i]] = 0;
            char_freq[s[i]]++;
        }

        for(int i=0; i<t.size(); i++){
            if(char_freq.find(t[i]) != char_freq.end())
                char_freq[t[i]]--;
            else
                char_freq[t[i]] = -1; // NOTE：注意此处t中出现，s中没有出现的字符
        }

        // 判断是否为有效异位词
        for(map<char, int>::iterator it=char_freq.begin(); it != char_freq.end(); ++it){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};

int main(){
//    string s="anagram", t="nagaram";
    string s="a", t="ab";

    cout<<Solution().isAnagram(s, t)<<endl;

    return 0;
}



