//
// Created by 陈志明 on 2020/6/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

/**
 * 调整堆的过程，从第i个结点开始调整堆
 * @param nums
 * @param i
 * @param n
 */
void adjustHeap(vector<int>& nums, int i, int n){
    if(i >= n)
        return;

    int maxIdx = i;
    int left = 2*i+1, right = 2*i+2;

    if(left < n && nums[left] > nums[maxIdx])
        maxIdx = left;
    if(right < n && nums[right] > nums[maxIdx])
        maxIdx = right;

    if(maxIdx != i){
        swap(nums[maxIdx], nums[i]);
        adjustHeap(nums, maxIdx, n);
    }
}

/**
 * 生成大顶堆，从最后一个非叶子结点开始调整
 * @param nums
 */
void makeHeap(vector<int>& nums){
    int n = nums.size();
    for(int i = (n-2)/2; i >= 0; i--){
        adjustHeap(nums, i, n);
    }
}

/**
 * 堆排序
 * @param nums
 * @return
 */
void heapSort(vector<int>& nums){
    int n = nums.size();
    for(int i = n-1; i >= 0; i--){
        swap(nums[i], nums[0]);
        adjustHeap(nums, 0, i); // 长度在缩小
    }
}


int main(){
    vector<int> nums = {1,6,5,3,2,8,9};

    // 构造大顶堆
    printVector(nums);
    makeHeap(nums);
    printVector(nums);

    // 堆排序
    heapSort(nums);
    printVector(nums);

    return 0;
}