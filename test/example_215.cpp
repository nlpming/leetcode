//
// Created by 陈志明 on 2020/6/11.
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        // 将大的排在pivot左边，小的排在右边
        while(left < right){
            while(left < right && nums[right] <= pivot)
                right--;
            nums[left] = nums[right];

            while(left < right && nums[left] >= pivot)
                left++;
            nums[right] = nums[left];
        }

        nums[left] = pivot;
        return left;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        assert(nums.size() > 0 && k <= nums.size() && k >= 1);
        if(nums.size() == 1 && k == 1)
            return nums[0];

        int left = 0, right = nums.size()-1;
        // 注意此处的终止条件left <= right
        while(left <= right){
            int pivot_idx = partition(nums, left, right);
            if(pivot_idx == k-1)
                return nums[pivot_idx];

            if(pivot_idx > k-1)
                right = pivot_idx-1;
            else
                left = pivot_idx+1;
        }

        return -1;
    }
};


int main(){
    vector<int> nums={2,1};
    Solution s;

    cout<<s.findKthLargest(nums, 2)<<endl;

    return 0;
}