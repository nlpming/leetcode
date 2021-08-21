//
// Created by 陈志明 on 2020/11/5.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

/*
 * 一趟快速排序思路：
 * 1. 先保存pivot = nums[left]；
 * 2. 从右到左找一个小于等于pivot的值，将其赋值给nums[left];
 * 3. 从左到右找一个大于等于pivot的值，将其赋值给nums[right];
 * 4. 循环执行步骤2，3；
 * 5. 将pivot的值赋值给nums[left];
 * */
int partition(vector<int>& nums, int left, int right){

    int pivot = nums[left]; //定义pivot值
    while(left < right){
        while(left < right && nums[right] >= pivot) //NOTE: 此处需要判断left < right；
            right--;
        nums[left] = nums[right];

        while(left < right && nums[left] <= pivot)
            left++;
        nums[right] = nums[left];
    }

    nums[left] = pivot; //将pivot赋值给nums[left]
    return left;
}


void quickSort(vector<int>& nums, int left, int right){

    //NOTE: 对数组[left...right]进行排序；【递归的，二分将数组进行排序；】
    if(left < right){
        int pivot_idx = partition(nums, left, right);
        printVector(nums);
        quickSort(nums, left, pivot_idx-1);
        quickSort(nums, pivot_idx+1, right);
    }
}

int main(){

    vector<int> nums = {5,4,1,5,3,2,8};

    printVector(nums);
    quickSort(nums, 0, nums.size()-1);
    printVector(nums);

    return 0;
}


