//
// Created by 陈志明 on 2021/10/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 考点：KMP算法
 * 难度：***
 * */
class Solution {
public:
    //时间复杂度：O(n+m);  n -> haystack长度；m -> needle长度；
    //空间复杂度：O(m);
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }

        //1. 生成部分匹配表；
        vector<int> pi(m, 0);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }

            pi[i] = j;
        }

        for (int i = 0, j = 0; i < n; i++) {
            //2. j回退到某个位置，继续开始比较；而不是从头开始比较；
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }

            //3. 找到匹配的子串；
            if (j == m) {
                return i - m + 1;
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("BBC ABCDAB ABCDABCDABDE", "ABDDABD") << endl;

    return 0;
}