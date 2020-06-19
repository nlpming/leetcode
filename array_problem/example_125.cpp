//
// Created by 陈志明 on 2020/5/9.
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * 题目描述：验证回文串
 * 考点：字符串，对撞指针
 * 是否做出：是
 */
class Solution {
public:
    bool isPalindrome(string s) {
        // 空字符串
        if(s == "")
            return true;

        int left=0, right=s.size()-1;

        // isalnum 判断是否为字母数字；tolower 将大写转为小写
        while(left <= right){
            if(!isalnum(s[left]))
                left++;
            else if(!isalnum(s[right]))
                right--;
            else{
                if(tolower(s[left]) == tolower(s[right])){
                    left++;
                    right--;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};


int main(){
    string input_s="A man, a plan, a canal: Panama";

    Solution s;
    cout<<s.isPalindrome(input_s)<<endl;

    return 0;
}



