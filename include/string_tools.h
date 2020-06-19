//
// Created by 陈志明 on 2020/5/12.
//

#ifndef WORKSPACE_STRING_H
#define WORKSPACE_STRING_H

#include <string>
#include <vector>
using namespace std;

class StringTools{

public:
    /**
     * 字符串切分
     * @param s
     * @param tokens
     * @param delimiters
     */
    void split(string s, vector<string>& tokens, string delimiters=" "){
        // 从第一个位置开始，找到第一个不是delimiters的index
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        // 从lastPos开始，找到第一个是delimiters的index
        string::size_type pos = s.find_first_of(delimiters, lastPos);

        while(string::npos != pos || string::npos != lastPos){
            tokens.push_back(s.substr(lastPos, pos-lastPos));
            lastPos = s.find_first_not_of(delimiters, pos);
            pos = s.find_first_of(delimiters, lastPos);
        }
    }
};

#endif //WORKSPACE_STRING_H
