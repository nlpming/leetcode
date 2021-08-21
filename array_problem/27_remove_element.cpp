//
// Created by 陈志明 on 2021/8/21.
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        int left = -1, right = 0; //left: 存储不为val的最后一个元素位置；
        while(right < nums.size()){
            if(nums[right] == val){
                right++;
            }else{
                left++; //找到一个不等于val的元素，left++
                swap(nums[left], nums[right]);
                right++;
            }
        }

        return left+1;
    }
};

