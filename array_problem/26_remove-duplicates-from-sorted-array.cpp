//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：滑动窗口指针
 * 难度：*
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();

        //注意：
        //1. left存放当前不重复元素的最后一个index；【0...left】为不重复的数组序列；
        //2. 滑动窗口指针；

        int left = 0, right = 0;
        while(right+1 < nums.size()){
            right++;

            if(nums[left] == nums[right]){
                continue;
            }else{
                left++;
                nums[left] = nums[right];
            }
        }

        return left+1;
    }
};