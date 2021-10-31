//
// Created by 陈志明 on 2021/10/30.
//
#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

void merge(vector<int>& nums, int left, int right){
    int mid = left + (right-left)/2;
    int p1 = left, p2 = mid+1;
    int p = 0;

    vector<int> res(right-left+1);
    while(p1 <= mid || p2 <= right){
        if(p1 > mid)
            res[p++] = nums[p2++];
        else if(p2 > right)
            res[p++] = nums[p1++];
        else{
            if(nums[p1] < nums[p2])
                res[p++] = nums[p1++];
            else
                res[p++] = nums[p2++];
        }
    }

    for(int i = 0; i < res.size(); i++){
        nums[left + i] = res[i];
    }

    return;
}

void mergeSort(vector<int>& nums, int left, int right){
    if(left == right)
        return;

    //二分数组，对左右两边分别排序；
    int mid = left + (right-left)/2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid+1, right);

    //合并排序后的left,right部分;
    merge(nums, left, right);

    return;
}

int main(){

    vector<int> nums = {1,3,2,4,5};

    printVector(nums);
    mergeSort(nums, 0, nums.size()-1);
    printVector(nums);

    return 0;
}



