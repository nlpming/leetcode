//
// Created by 陈志明 on 2020/5/19.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/**
 * 题目描述：逆波兰表达式求值
 * 考点：栈
 * 是否做出：是
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums_stack;

        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                if(!nums_stack.empty()){
                    int first_num = nums_stack.top(); nums_stack.pop();
                    int second_num = nums_stack.top(); nums_stack.pop();
                    int result;

                    if(tokens[i] == "+")
                        result = second_num + first_num;
                    else if(tokens[i] == "-")
                        result = second_num - first_num;
                    else if(tokens[i] == "*")
                        result = second_num * first_num;
                    else
                        result = second_num / first_num;

                    nums_stack.push(result);
                }
            }
            else{
                // string转为int
                nums_stack.push(stoi(tokens[i]));
            }
        }

        return nums_stack.top();
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    cout<<Solution().evalRPN(tokens)<<endl;


    return 0;
}