//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：双指针
 * 难度：**
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();

        int left = 0, right = 0;
        while(right+1 < nums.size()){
            right++;

            if(nums[left] == nums[right]){
                //nums[left-1] == nums[left]则继续right++【1.两个数字连续出现】
                if(left - 1 >= 0 && nums[left] == nums[left-1]){
                    continue;
                }else{ //【2.新的两个数字连续出现】
                    left++;
                    nums[left] = nums[right];
                }
            }else{
                // 【3.新的数字出现】
                left++;
                nums[left] = nums[right];
            }
        }

        return left+1;
    }
};