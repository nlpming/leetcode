//
// Created by 陈志明 on 2021/8/28.
//

#include <iostream>
#include <vector>
#include "print.h"

vector<int> merge(vector<int> left_nums, vector<int> right_nums){
    vector<int> res;
    int left = 0, right = 0;

    while(left < left_nums.size() && right < right_nums.size()){
        if(left_nums[left] < right_nums[right]){
            res.push_back(left_nums[left]);
            left++;
        }else{
            res.push_back(right_nums[right]);
            right++;
        }
    }

    while(left < left_nums.size()){
        res.push_back(left_nums[left]);
        left++;
    }

    while(right < right_nums.size()){
        res.push_back(right_nums[right]);
        right++;
    }

    return res;
}

vector<int> mergeSort(vector<int> nums){
    if(nums.size() <= 1)
        return nums;

    int n = nums.size();
    int mid = n/2;
    vector<int> left_nums, right_nums;

    //NOTE: 切分过程
    for(int i = 0; i < n; i++){
        if(i < mid)
            left_nums.push_back(nums[i]);
        else
            right_nums.push_back(nums[i]);
    }

    left_nums = mergeSort(left_nums);
    right_nums = mergeSort(right_nums);

    //Merge过程
    vector<int> res = merge(left_nums, right_nums);
    return res;
}


int main(){

    vector<int> nums = {1,3,2,10,30,8};
    printVector(nums);

    vector<int> res = mergeSort(nums);
    printVector(res);

    return 0;
}