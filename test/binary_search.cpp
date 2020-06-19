//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int binarySearch(vector<int> nums, int target){
        if(nums.empty())
            return -1;

        int left = 0, right = nums.size()-1;
        // 注意范围：[0, nums.size()-1]
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }

        return -1;
    }
};


int main(){
    vector<int> nums = {1,5,7,8,9};
    cout << Solution().binarySearch(nums, 8) << endl;

    return 0;
}




