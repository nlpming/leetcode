//
// Created by 陈志明 on 2020/6/11.
//
#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

template <typename T>
int partition(vector<T>& nums, int left, int right){
    // 一趟快速排序
    T pivot = nums[left];

    while(left < right){
        while(left < right && nums[right] >= pivot)
            right --;
        nums[left] = nums[right];

        while(left < right && nums[left] <= pivot)
            left ++;
        nums[right] = nums[left];
    }
    // pivot赋值
    nums[left] = pivot;
    return left;
}
/**
 * 快速排序
 * @tparam T
 * @param nums
 * @param left
 * @param right
 */
template <typename T>
void quickSort(vector<T>& nums, int left, int right){
    if(left < right){
        int pivot_idx = partition(nums, left, right);
        quickSort(nums, left, pivot_idx-1);
        quickSort(nums, pivot_idx+1, right);
    }
}


int main(){

    vector<int> nums={1,4,5,3,2};

    printVector(nums);
    quickSort(nums, 0, 4);
    printVector(nums);

    return 0;
}