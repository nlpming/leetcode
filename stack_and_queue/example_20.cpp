//
// Created by 陈志明 on 2020/5/18.
//
#include <string>
#include <stack>
#include "print.h"
using namespace std;

/**
 * 题目描述：有效的括号
 * 考点：栈
 * 是否做出：是
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_ch;
        for(int i=0; i<s.size(); i++){
            if(stack_ch.empty()){
                stack_ch.push(s[i]);
            }
            else{
                char top_ch = stack_ch.top();
                if(top_ch == '(' && s[i] == ')')
                    stack_ch.pop();
                else if(top_ch == '[' && s[i] == ']')
                    stack_ch.pop();
                else if(top_ch == '{' && s[i] == '}')
                    stack_ch.pop();
                else{
                    // 左括符入栈
                    if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                        stack_ch.push(s[i]);
                    else
                        return false;
                }
            }
        }

        // 全部为左括符情况
        if(stack_ch.empty())
            return true;
        else
            return false;
    }
};

int main() {


    return 0;
}