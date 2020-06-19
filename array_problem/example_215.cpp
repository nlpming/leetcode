//
// Created by 陈志明 on 2020/5/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void printVector(vector<T> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

/**
 * 题目描述：数组中的第K个最大元素
 * 考点：数组、快速排序
 * 是否做出：否
 */
class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        return findProcess(v, 0, v.size()-1, k);
    }

    int findProcess(vector<int>& v, int left, int right, int k){
        // 找到第index+1个最大元素
        int index = partition(v, left, right);

        if(index+1 == k) return v[index];
        else if(index+1 < k) return findProcess(v, index+1, right, k );
        else if(index+1 > k) return findProcess(v, left, index-1, k);

        return -1;
    }

    int partition(vector<int>& v, int left, int right){
        // 一趟快速排序；将大的值放置在pivot左边，小的放在pivot右边
        int pivot = v[left];

        while(left < right){
            while(left < right && v[right] <= pivot)
                right--;
            v[left] = v[right];

            while(left < right && v[left] >= pivot)
                left++;
            v[right] = v[left];
        }
        v[left] = pivot;
        return left;
    }
};

int main(){
    vector<int> nums={3,2,1,5,6,4};

    Solution s;

    printVector(nums);
    cout<<s.findKthLargest(nums, 2)<<endl;
    printVector(nums);


    return 0;
}




