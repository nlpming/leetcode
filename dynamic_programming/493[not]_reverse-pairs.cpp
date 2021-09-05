//
// Created by 陈志明 on 2021/9/2.
//

class Solution {
public:
    int merge(vector<int> &nums, int left, int mid, int right){

    }

    int helper(vector<int> &nums, int left, int right){
        if(nums.size() == 1)
            return 0;

        int mid = num.size()/2;

        //1. 统计left,right两个数组的翻转对数；
        int left_num = reversePairs(nums, left, mid);
        int right_num = reversePairs(nums, mid+1, right);

        //2. 统计left, right交叉的翻转对数；
        int cross_num = merge(nums, left, mid, right);

        return left_num + right_num + cross_num;
    }

    int reversePairs(vector<int>& nums) {

    }
};

