//
// Created by 陈志明 on 2021/10/25.
//

class Solution {
private:
    int count(string s, int start, int end){
        int num = 0;
        while(start >= 0 && end < s.size() && s[start] == s[end]){
            num++;
            start--;
            end++;
        }

        return num;
    }

public:
    int countSubstrings(string s) {
        int res = 0;
        //注意：
        //1. 从某个位置开始，向外扩展；【中心扩展法】
        //2. 区分回文串为奇数、或者偶数的情况；

        for(int i = 0; i < s.size(); i++){
            res += count(s, i, i); //回文串长度为奇数；
            res += count(s, i, i+1); //回文串长度为偶数；
        }

        return res;
    }
};