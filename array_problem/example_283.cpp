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
 * 题目描述：移动零
 * 考点：数组，双指针
 * 是否做出：是
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0, q=0;

        while(q < nums.size()){
            if(nums[q] != 0){
                swap(nums[p], nums[q]);
                p++;
                q++;
            }
            else{
                q++;
            }
        }
    }
};

int main(){
    vector<int> nums={0,1,0,3,12};

    Solution s;

    printVector(nums);
    s.moveZeroes(nums);
    printVector(nums);

    return 0;
}

