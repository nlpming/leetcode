//
// Created by 陈志明 on 2020/6/17.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0}; // 存储字符ascii，判断是否重复
        int left = 0, right = -1; // 滑动窗口初始为：[0, -1] 空窗口
        int res = 0;

        // 滑动窗口结束为：[s.length(), s.length()-1] 空窗口
        while(left < s.length()){
            if(right+1 < s.length() && freq[s[right+1]] == 0){
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
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;

    return 0;
}

