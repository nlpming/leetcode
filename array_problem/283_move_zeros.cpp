//
// Created by 陈志明 on 2021/8/21.
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        int left = 0, right = 0; //双指针，left存放从左到右不为0的，第一个位置；

        while(right < nums.size()){
            if(nums[right] != 0){
                swap(nums[left], nums[right]);
                left++;
                right++;
            }else{
                right++;
            }
        }
    }
};