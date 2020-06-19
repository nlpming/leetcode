//
// Created by 陈志明 on 2020/5/21.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include "print.h"

using namespace std;

/*
 * 堆的定义如下：n个元素的序列{k1,k2,...,kn}当且仅当满足如下关系时，称之为堆：
 * (1) ki <= k2i && ki <= k2i+1;  (最小堆)
 * (2) ki >= k2i && ki >= k2i+1;  (最大堆)
 * 堆中第i个结点的左孩子结点2*i+1，右孩子结点2*i+2；父结点为(i-1)/2;
 * 堆中第一个非叶结点(length-2)/2, 堆中最后一个结点的父结点;
 * 堆排序时间复杂度：O(nlogn);
 */


/**
 * 从某个结点i开始，调整堆中的元素，使之构成堆
 * @param nums
 * @param i
 * @param length
 */
void adjustHeap(vector<int>& nums, int i, int length){
    // 递归终止条件
    if(i >= length) return;

    int left = 2*i+1, right = 2*i+2;
    int max_idx = i;

    // 找到3个结点中的最大值
    if(left < length && nums[left] > nums[max_idx])
        max_idx = left;
    if(right < length && nums[right] > nums[max_idx])
        max_idx = right;

    // 交换数据
    if(max_idx != i) {
        swap(nums[i], nums[max_idx]);
        // 继续调整后续结点
        adjustHeap(nums, max_idx, length);
    }
}

/**
 * 堆排序
 * @param nums
 * @return
 */
vector<int> heapSort(vector<int> nums){
    vector<int> res(nums.begin(), nums.end());
    for(int i = res.size()-1; i >= 0; i--){
        // 交换最后一个元素，堆顶元素
        swap(res[i], res[0]);
        adjustHeap(res, 0, i);
    }
    return res;
}

/**
 * 构建最大堆
 * @param nums
 */
void makeHeap(vector<int>& nums){
    for(int i = (nums.size()-2)/2; i >=0; i--){
        adjustHeap(nums, i, nums.size());
    }
}

int main() {

    vector<int> nums = {1,6,2,5,3,4};

    printVector(nums);
    adjustHeap(nums, 0, nums.size());
    printVector(nums);

//    printVector(heapSort(nums));

    return 0;
}