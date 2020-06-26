//
// Created by 陈志明 on 2020/6/21.
//
#include <iostream>
#include <vector>
#include <string>
#include "print.h"

using namespace std;

/**
 * s,p中只包含小写英文字母
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length() < p.length())
            return res;

        // p中字符出现的次数
        vector<int> record(26, 0);
        for(int i = 0; i < p.length(); i++){
            record[p[i]-'a']++;
        }

        int left = 0, right = -1;
        // 滑动窗口中字符出现的次数
        vector<int> temp(26, 0);

        // 注意：left,right取值范围
        while(left <= s.length()-p.length()){
            if(right+1 < s.length() && right-left+1 < p.length()){
                right++;
                temp[s[right]-'a']++;
            }
            else{
                if(temp == record) // NOTE: vector可直接比较
                    res.push_back(left);

                temp[s[left]-'a']--;
                left++;
            }
        }

        return res;
    }
};

int main(){

    string s = "abab";
    string p = "ab";
    vector<int> res;

    res = Solution().findAnagrams(s, p);
    printVector(res);

    return 0;
}

