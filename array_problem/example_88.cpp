//
// Created by 陈志明 on 2020/4/29.
//
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(vector<T> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

/*
 * 题目描述：合并两个有序数组
 * 考点：数组，三指针
 * 是否做出：是
 * */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 从后往前移动，p、q、last指针；last指示nums1最后一个元素；
        int last=m+n-1;
        int p=m-1, q=n-1;

        // 注意终止条件，需要遍历完所有nums2中的元素
        while(q >= 0){
            // 注意m=0的情况
            if(p >=0 && nums1[p] > nums2[q]){
                nums1[last] = nums1[p];
                p--;
                last--;
            }
            else{
                nums1[last] = nums2[q];
                q--;
                last--;
            }
        }
    }
};


int main(){

    Solution s;

    vector<int> nums1 = {0};
    vector<int> nums2 = {1};

    cout<<"nums1: ";
    printVector(nums1);
    cout<<"nums2: ";
    printVector(nums2);

    s.merge(nums1, 0, nums2, 1);
    printVector(nums1);

    return 0;
}



