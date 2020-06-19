//
// Created by 陈志明 on 2020/6/17.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 存储字符ascii，共256个字符
        int freq[256] = {0};
        // 滑动窗口初始为：left = 0, right = -1 的空窗口
        int left = 0, right = -1, res = 0;

        // 滑动窗口结束为：left = s.length(), right = s.length()-1
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

