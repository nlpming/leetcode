//
// Created by 陈志明 on 2021/8/26.
//

/*
 * 考点：栈
 * 难度：*
 * 题名：20.有效的括号
 * */
class Solution {
public:
    bool isMatch(char topChar, char ch){
        if(topChar == '(' && ch == ')')
            return true;
        else if(topChar == '[' && ch == ']')
            return true;
        else if(topChar == '{' && ch == '}')
            return true;
        return false;
    }

    bool isValid(string s) {
        int n = s.size();
        stack<char> record;

        for(int i = 0; i < n; i++){
            if(record.empty()){
                record.push(s[i]);
            }else{
                char topChar = record.top();
                //栈顶出现下面三个字符，直接返回；
                if(topChar == ')' || topChar == '}' || topChar == ']')
                    return false;

                if(isMatch(topChar, s[i]))
                    record.pop();
                else
                    record.push(s[i]);
            }
        }

        if(record.empty())
            return true;
        else
            return false;
    }
};