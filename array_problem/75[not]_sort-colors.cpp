//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：三指针
 * 难度：**
 * */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();

        // 注意：
        // 1. cur指针的终止为：right-1;
        // 2. 当nums[cur] == 1的时候，只需要cur++即可；
        // 3. 当nums[cur] == 0的时候，交换完nums[left], nums[cur]；也需要将cur++；
        for(int cur = 0; cur < right; ){
            if(nums[cur] == 0){
                left++;
                swap(nums[left], nums[cur]);
                cur++;  //【NOTE: 因为nums[left+1]肯定为1】
            }else if(nums[cur] == 2){
                right--;
                swap(nums[right], nums[cur]);
            }else{
                cur++;
            }
        }
    }
};