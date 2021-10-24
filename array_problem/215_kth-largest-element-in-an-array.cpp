//
// Created by 陈志明 on 2021/8/21.
//

/*
 * 考点：快速排序；
 * 难度：***
 * */
class Solution {
public:

    //一趟快速排序：注意是将大的元素，放在pivot的左边；
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left]; //NOTE: 从大到小排序；
        while(left < right){
            while(left < right && nums[right] <= pivot) //小于等于
                right--;
            nums[left] = nums[right];

            while(left < right && nums[left] >= pivot)
                left++;
            nums[right] = nums[left];
        }

        nums[left] = pivot;
        return left;
    }

    //NOTE: 需要新增helper函数；
    int helper(vector<int>& nums, int left, int right, int k){
        int pivot_idx = partition(nums, left, right);
        if(pivot_idx + 1 == k){ //NOTE: 找到第k大的元素；
            return nums[pivot_idx];
        }

        //查找范围缩小：[left...pivot_idx-1], [pivot_idx+1...right]
        if(pivot_idx < k){ //NOTE: 第k大的元素，在右边；
            return helper(nums, pivot_idx+1, right, k);
        }else{
            return helper(nums, left, pivot_idx-1, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size()-1, k);
    }
};