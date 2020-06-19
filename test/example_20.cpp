//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    bool valid(char top, char ch){
        if(top == '(' && ch == ')')
            return true;
        else if(top == '[' && ch == ']')
            return true;
        else if(top == '{' && ch == '}')
            return true;

        return false;
    }
public:
    bool isValid(string s) {
        stack<char> record;

        for(int i = 0; i < s.length(); i++){
            if(record.empty()){
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    record.push(s[i]);
                else
                    return false;
            }
            else{
                char top = record.top();
                if(valid(top, s[i]))
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


int main(){
    string s = "()[(]{}";
    cout << Solution().isValid(s) << endl;

    return 0;
}