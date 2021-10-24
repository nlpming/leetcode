//
// Created by 陈志明 on 2020/11/5.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

vector<int> merge(vector<int> left, vector<int> right){
    vector<int> res;
    int i = 0, j = 0;

    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            res.push_back(left[i]);
            ++i;
        } else {
            res.push_back(right[j]);
            ++j;
        }
    }

    while(i < left.size()){
        res.push_back(left[i]);
        ++i;
    }

    while(j < right.size()){
        res.push_back(right[j]);
        ++j;
    }

    return res;
}

vector<int> mergeSort(vector<int>& nums){
    //NOTE: 容易忽略；
    if(nums.size() == 1)
        return nums;

    // 1.二分过程；
    int mid = nums.size()/2;
    vector<int> nums_left, nums_right;

    for(int i = 0; i < nums.size(); i++){
        if(i < mid)
            nums_left.push_back(nums[i]);
        else
            nums_right.push_back(nums[i]);
    }

    // 2.排序过程；
    vector<int> left = mergeSort(nums_left);
    vector<int> right = mergeSort(nums_right);

    // 3.合并排序后的数组；
    return merge(left, right);
}


int main(){
    vector<int> nums = {1,4,5,5,3,2,8};

    printVector(nums);
    vector<int> nums_sort = mergeSort(nums);
    printVector(nums_sort);

    return 0;
}

