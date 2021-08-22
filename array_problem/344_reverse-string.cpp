//
// Created by 陈志明 on 2021/8/22.
//

/*
 * 考点：对撞指针；
 * 难度：*
 * */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;

        //两个指针left,right相向移动；
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return;
    }
};