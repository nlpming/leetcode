//
// Created by 陈志明 on 2020/5/7.
//

/**
 * 排序算法汇总
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 打印数组
 * @tparam T
 * @param nums
 */
template <typename T>
void printVector(vector<T> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

/**
 * 冒泡排序
 * @tparam T
 * @param nums
 */
template <typename T>
void bubbleSort(vector<T>& nums){

    for(int i=0; i<nums.size()-1; i++){
        for(int j=0; j<nums.size()-i-1; j++){
            if(nums[j] > nums[j+1]){
                //T temp;
                //temp = nums[j];
                //nums[j] = nums[j+1];
                //nums[j+1] = temp;
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

/**
 * 插入排序
 * @tparam T
 * @param nums
 */
template <typename T>
void insertionSort(vector<T>& nums){
    if(nums.size() <= 1)
        return;

    // i=1开始进行插入排序，i之前的数据已经排好序
    for(int i=1; i<nums.size(); i++){
        T curNum = nums[i];
        int j = i-1;
        while(j>=0 && curNum < nums[j]){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = curNum;
    }
}

/**
 * 选择排序
 * @tparam T
 * @param nums
 */
template <typename T>
void selectionSort(vector<T>& nums){
    if(nums.size() <= 1)
        return;

    // 遍历nums.size()-1次
    for(int i=0; i<nums.size()-1; i++){
        int minIndex = i;
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j] < nums[minIndex])
                minIndex = j;
        }
        if(minIndex != i)
            swap(nums[minIndex], nums[i]);
    }
}

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
        int pivot_index = partition(nums, left, right);
        quickSort(nums, left, pivot_index-1);
        quickSort(nums, pivot_index+1, right);
    }
}

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

//    printVector(nums);
//    bubbleSort(nums);
//    printVector(nums);

//     printVector(nums);
//     insertionSort(nums);
//     printVector(nums);

//     printVector(nums);
//     selectionSort(nums);
//     printVector(nums);

//    printVector(nums);
//    quickSort(nums, 0, 4);
//    printVector(nums);

    printVector(nums);
    vector<int> nums_sorted = mergeSort(nums);
    printVector(nums_sorted);

    return 0;
}




