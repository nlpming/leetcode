//
// Created by 陈志明 on 2020/5/12.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * 题目描述：同构字符串
 * 考点：哈希表
 * 是否做出：是
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> char_char_map;

        if(s.size() != t.size())
            return false;

        for(int i=0; i<s.size(); i++){
            if(char_char_map.find(s[i]) == char_char_map.end()){
                // 查看新key，value是否已在map中出现
                for(map<char, char>::iterator it=char_char_map.begin(); it!=char_char_map.end(); ++it)
                    if(it->second == t[i])
                        return false;
                char_char_map[s[i]] = t[i];
            }
            else{
                if(char_char_map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main(){
    string s="ab", t="aa";
    cout<<Solution().isIsomorphic(s, t);

    return 0;
}
