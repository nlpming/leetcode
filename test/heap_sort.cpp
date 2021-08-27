//
// Created by 陈志明 on 2021/8/28.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

void adjustHeap(vector<int>& nums, int k, int n){
    if(k >= n) return;
    int left = 2*k+1;
    int right = 2*k+2;
    int maxIdx = k;

    if(left < n && nums[left] > nums[k]){
        maxIdx = left;
    }
    if(right < n && nums[right] > nums[k]){
        maxIdx = right;
    }

    if(maxIdx != k){
        swap(nums[k], nums[maxIdx]);
        adjustHeap(nums, maxIdx, n);
    }
}

void makeHeap(vector<int>& nums){
    int n = nums.size();
    for(int i = (n-2)/2; i >= 0; i--){
        adjustHeap(nums, i, n);
    }
}

void heapSort(vector<int>& nums){
    int n = nums.size();
    for(int i = n-1; i >= 0; i--){
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i);
    }
}

int main(){
    vector<int> nums = {1,3,5,2,4,10};
    printVector(nums);

    makeHeap(nums);
    printVector(nums);

    heapSort(nums);
    printVector(nums);

    return 0;
}




