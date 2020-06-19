//
// Created by 陈志明 on 2020/5/11.
//
#include <iostream>
#include <string>
#include <map>
#include <utility>

#include "print.h"
#include "string_tools.h"

using namespace std;

/**
 * 题目描述：单词规律
 * 考点：哈希表
 * 是否做出：是
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {

        StringTools st;
        map<char, string> char_str_map;
        map<string, char> str_char_map;

        vector<string> tokens;
        st.split(str, tokens, string(" "));

        // 长度不等直接返回
        if(pattern.size() != tokens.size()){
            return false;
        }

        // char,str必须是一一对应关系
        for(int i=0; i<pattern.size(); i++){
            if(char_str_map.find(pattern[i]) == char_str_map.end())
                char_str_map.insert(pair<char, string>(pattern[i], tokens[i]));
            else{
                if(char_str_map[pattern[i]] != tokens[i])
                    return false;
            }

            if(str_char_map.find(tokens[i]) == str_char_map.end())
                str_char_map.insert(pair<string, char>(tokens[i], pattern[i]));
            else{
                if(str_char_map[tokens[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
};

int main(){
    string pattern="abba", str="dog cat cat dog";
    cout<<Solution().wordPattern(pattern, str);

    return 0;
}