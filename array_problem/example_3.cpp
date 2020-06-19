//
// Created by 陈志明 on 2020/5/10.
//
#include <iostream>
#include <string>
using namespace std;

/**
 * 题目描述：无重复字符的最长子串
 * 考点：数组、滑动窗口指针
 * 是否做出：否
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 整形数组，存储字符的ascii
        int freq[256] ={0};
        int left=0, right=-1, res=0; // 滑动窗口为[left, right]

        // 整个循环从：left=0, right=-1 空窗口开始
        // left=s.size(), right=s.size()-1 空窗口结束
        while(left < s.size()){
            if(right+1 < s.size() && freq[s[right+1]] == 0){
                right++;
                freq[s[right]]++;
            }
            else{
                freq[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};



int main(){
    string s="au";
    cout<<Solution().lengthOfLongestSubstring(s)<<endl;

    return 0;
}