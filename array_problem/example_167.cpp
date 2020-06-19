//
// Created by 陈志明 on 2020/5/9.
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

/**
 * 题目描述：两数之和 II - 输入有序数组
 * 考点：数组，对撞指针
 * 是否做出：是
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        vector<int> res;

        while(i < j){
            int sum_val = numbers[i]+numbers[j];
            if(sum_val == target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(sum_val > target){
                j--;
            }
            else
                i++;
        }

        return res;
    }
};


int main(){
    vector<int> nums={2, 7, 11, 15};
    int target=9;

    Solution s;
    printVector(s.twoSum(nums, target));

    return 0;
}




