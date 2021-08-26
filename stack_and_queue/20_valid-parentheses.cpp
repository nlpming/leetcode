//
// Created by 陈志明 on 2021/8/26.
//

/*
 * 考点：栈
 * 难度：*
 * */
class Solution {
public:
    bool checkValid(char left, char right){
        if(left == '[' && right == ']'){
            return true;
        }else if(left == '(' && right == ')'){
            return true;
        }else if(left == '{' && right == '}'){
            return true;
        }

        return false;
    }

    bool isValid(string s) {
        if(s.length() == 0) return true;

        stack<char> record;
        for(int i = 0; i < s.length(); i++){
            if(record.empty()){
                record.push(s[i]);
            }else{
                char left = record.top();
                //NOTE: 如果匹配，则栈顶字符出栈；
                if(checkValid(left, s[i])){
                    record.pop();
                }else{
                    //NOTE: 遇到右括号不匹配则直接返回【注意此处】
                    if(s[i] == ']' || s[i] == ')' || s[i] == '}')
                        return false;
                    else
                        record.push(s[i]);
                }
            }
        }

        //NOTE: 判断栈是否为空；
        if(record.empty())
            return true;
        else
            return false;
    }
};