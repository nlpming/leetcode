//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 解题思路：双指针【滑动窗口指针】
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();

        int left = 0, right = 0; //left存放当前不重复元素的最后一个index；
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