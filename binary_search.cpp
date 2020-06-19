//
// Created by 陈志明 on 2020/5/8.
//
#include <iostream>
#include <vector>
using namespace std;

/**
 * 二分查找
 * @param nums
 * @param target
 * @return
 */
int binary_search(vector<int> nums, int target){
    if(nums.size() < 1)
        return -1;

    // 在[left, right]中查找
    int left=0, right=nums.size()-1;

    while(left <= right){
        int mid=(left+right)/2;
        if(nums[mid] == target)
            return mid;

        if(target > nums[mid])
            left = mid+1;
        else
            right = mid-1;
    }

    return -1;
}

int main(){

    vector<int> nums={1,3,5,7,9,11};
    cout<<binary_search(nums, 7)<<endl;


    return 0;
}




