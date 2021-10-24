//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：滑动窗口指针；
 * 难度：*
 * */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        int left = -1, right = 0; //双指针，left存放从左到右不为0的，第一个位置；

        while(right < nums.size()){
            if(nums[right] != 0){
                left++;
                swap(nums[left], nums[right]);
                right++;
            }else{
                right++;
            }
        }
    }
};