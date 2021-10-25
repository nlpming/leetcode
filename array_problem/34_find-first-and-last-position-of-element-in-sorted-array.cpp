//
// Created by 陈志明 on 2021/10/25.
//

/*
 * 考点：二分查找；
 * 难度：**
 * */
class Solution {
private:
    int binarySearch(vector<int> nums, int target, bool flag){
        int res = -1;
        int left = 0, right = nums.size()-1;

        while(left <= right){
            int mid = left + (right - left)/2;
            //NOTE: 相等的时候特殊处理；
            if(nums[mid] == target){
                res = mid;
                if(flag) //NOTE: 查找左边界；
                    right = mid-1;
                else
                    left = mid+1;
            }else{
                if(nums[mid] > target)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }

        return res;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);

        //NOTE: 执行两次二分查找；
        res[0] = binarySearch(nums, target, true);
        res[1] = binarySearch(nums, target, false);

        return res;
    }
};