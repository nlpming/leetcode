//
// Created by 陈志明 on 2020/5/8.
//
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

/**
 * 题目描述： 移除元素; NOTE: 你不需要考虑数组中超出新长度后面的元素。
 * 考点：数组，双指针
 * 是否做出：是
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val)
                nums[j++] = nums[i];
        }

        return j;
    }
};

int main(){
    vector<int> nums={3,2,2,3};

    Solution s;
    cout<<s.removeElement(nums, 3)<<endl;
    printVector(nums);

    return 0;
}


