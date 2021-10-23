//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：三指针 【三路快速排序】
 * 难度：**
 * */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size(), cur = 0;

        // 注意：
        // 1. cur指针的终止为：right-1;
        // 2. 当nums[cur] == 1的时候，只需要cur++即可；
        // 3. 当nums[cur] == 0的时候，交换完nums[left], nums[cur]；也需要将cur++；
        // 4. [0...left]存储为0的所有元素，[right...nums.size()-1]存储为2的所有元素；

        while(cur < right){
            if(nums[cur] == 0){
                left++;
                swap(nums[left], nums[cur]);
                cur++;  //nums[left+1]的元素为1；【注意此处，易忽略】
            }else if(nums[cur] == 2){
                right--;
                swap(nums[right], nums[cur]);
            }else{
                cur++;
            }
        }
    }
};