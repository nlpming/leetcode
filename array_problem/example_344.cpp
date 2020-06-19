//
// Created by 陈志明 on 2020/5/9.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

/**
 * 题目描述：反转字符串
 * 考点：数组，对撞指针
 * 是否做出：是
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0, right=s.size()-1;

        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main(){
    vector<char> input_char={'h','e','l','l','o'};

    Solution s;

    printVector(input_char);
    s.reverseString(input_char);
    printVector(input_char);

    return 0;
}




