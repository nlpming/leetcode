//
// Created by 陈志明 on 2021/8/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * 二分查找：迭代实现；
     * */
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;

        int left = 0, right = nums.size() - 1; //在[left,...,right]区间寻找target；
        while (left <= right) { // 当left == right时，区间[left,...,right]仍然是有效的；
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

class Solution1{
public:
    /*
     * 二分查找：递归实现；
     * */
    int helper(vector<int>& nums, int left, int right, int target){
        if(left <= right){
            int mid = left + (right-left)/2;
            int result = -1;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                result = helper(nums, left, mid-1, target);
            }else{
                result = helper(nums, mid+1, right, target);
            }

            return result;
        }else{
            return -1;
        }
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        return helper(nums, 0, nums.size()-1, target);
    }
};


int main(){

    vector<int> nums = {1,3,4,7,9,11};
    Solution s;
    cout << s.search(nums, 9) << endl;

    Solution1 s1;
    cout << s1.search(nums, 9) << endl;

    return 0;
}