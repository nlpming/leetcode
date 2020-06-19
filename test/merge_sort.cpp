//
// Created by 陈志明 on 2020/6/11.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

template <typename T>
vector<T> merge(vector<T> left, vector<T> right){
    // 将排序好的数组left, right归并
    vector<T> result;
    int i=0, j=0;

    while(i < left.size() && j < right.size()){
        if(left[i] < right[j]){
            result.push_back(left[i]);
            i ++;
        }else{
            result.push_back(right[j]);
            j ++;
        }
    }

    //剩余元素存入vector中
    while(i < left.size()){
        result.push_back(left[i]);
        i ++;
    }

    while(j < right.size()){
        result.push_back(right[j]);
        j ++;
    }
    return result;
}

/**
 * 归并排序
 * @tparam T
 * @param nums
 * @return
 */
template <typename T>
vector<T> mergeSort(vector<T> nums){

    if(nums.size() == 1)
        return nums;

    // 二分数组
    // NOTE: vector没有分片初始化算法
    int mid = nums.size()/2;
    vector<T> nums_left, nums_right;

    for(int i=0; i<nums.size(); i++){
        if(i < mid)
            nums_left.push_back(nums[i]);
        else
            nums_right.push_back(nums[i]);
    }

    // 分别对左右两边进行排序
    vector<T> left = mergeSort(nums_left);
    vector<T> right = mergeSort(nums_right);

    return merge(left, right);
}

int main(){

    vector<int> nums={1,4,5,3,2};

    printVector(nums);
    vector<int> nums_sorted = mergeSort(nums);
    printVector(nums_sorted);

    return 0;
}



