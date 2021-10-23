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

        //注意：
        //1. 如何判断出现重复次数，超过2次；
        //2. 双指针，终止条件right+1 < nums.size()；

        int left = 0, right = 0;
        while(right+1 < nums.size()){
            right++;

            if(nums[left] == nums[right]){
                // nums[left-1] == nums[left]，则继续right++；【1. 出现重复超过2次的相同数字】
                if(left - 1 >= 0 && nums[left] == nums[left-1]){
                    continue;
                }else{
                    //2. 出现相同数字；
                    left++;
                    nums[left] = nums[right];
                }
            }else{
                //3. 出现新的数字；
                left++;
                nums[left] = nums[right];
            }
        }

        return left+1;
    }
};