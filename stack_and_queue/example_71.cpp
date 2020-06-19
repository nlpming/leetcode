//
// Created by 陈志明 on 2020/5/19.
//
#include <iostream>
#include <string>
#include <stack>
#include "print.h"
using namespace std;

/**
 * 题目描述：简化路径
 * 考点：栈
 * 是否做出：否
 */
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> str_stack; // 存放字母序列
        path += "/"; // 避免处理末尾 /
        string temp, result; // 数据先暂时放在temp

        for(int i=0; i < path.length(); i++){
            if (path[i] == '/' && str_stack.empty() && temp == ""){
                continue;
            }

            if (path[i] == '/') {
                if (temp == "." || temp == ""){
                    // 空语句
                }else if (temp == ".."){
                    if (!str_stack.empty()) str_stack.pop();
                }else{
                    str_stack.push(temp);
                }
                temp = "";
            }
            else
                temp.push_back(path[i]); // string中压入字符
        }

        // 构造结果
        if (str_stack.empty()) return "/";
        while (!str_stack.empty()){
            result = "/" + str_stack.top() + result;
            str_stack.pop();
        }
        return result;
    }
};

int main() {
    string path = "/home//foo/";
    cout<<Solution().simplifyPath(path)<<endl;

    return 0;
}