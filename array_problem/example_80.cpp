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
 * 题目描述：删除排序数组中的重复项 II
 * 考点：数组，双指针
 * 是否做出：是
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length < 3)
            return length;

        // 双指针，滑动窗口
        int i=0, j=2;
        while(j < length){
            if(nums[i] == nums[i+1] && nums[i+1] == nums[j]){
                for(int k=j; k<length-1; k++)
                    nums[k] = nums[k+1];
                length--;
            }
            else{
                i++;
                j++;
            }
        }
        return length;
    }
};

int main(){

    vector<int> nums = {1,1,1,2,3};
    printVector(nums);

    Solution s;
    cout<<s.removeDuplicates(nums)<<endl;
    printVector(nums);


    return 0;
}






