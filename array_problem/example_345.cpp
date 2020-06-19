//
// Created by 陈志明 on 2020/5/9.
//
#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

/**
 * 题目描述：反转字符串中的元音字母
 * 考点：字符串、对撞指针
 * 是否做出：是
 */
class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels={'a','e','i','o','u'};
        int left=0, right=s.size()-1;

        // 在判断元音的时候，需要先转为小写
        while(left < right){
            if(vowels.find(tolower(s[left])) == vowels.end())
                left++;
            else if(vowels.find(tolower(s[right])) == vowels.end())
                right--;
            else{
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main(){
    string input_s="leetcode";

    Solution s;
    cout<<input_s<<endl;
    cout<<s.reverseVowels(input_s)<<endl;

    return 0;
}





