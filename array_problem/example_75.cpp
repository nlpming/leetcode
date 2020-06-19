//
// Created by 陈志明 on 2020/5/8.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printVector(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

/**
 * 题目描述：颜色分类
 * 考点：数组，三指针
 * 是否做出：是
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {

        // [...left] 都为0；[right...] 都为2；
        int left=-1, right=nums.size();
        int i=0;

        // 三指针技术
        while(i < right){
            if(nums[i] == 0){
                left++;
                // 此处容易犯错
                if(i == left)
                    i++;
                else
                    swap(nums[left], nums[i]);
            }
            else if(nums[i] == 2){
                swap(nums[--right], nums[i]);
            }
            else{
                i++;
            }
        }
    }
};

int main(){

    vector<int> nums={2,0,2,1,1,0};

    Solution s;

    printVector(nums);
    s.sortColors(nums);
    printVector(nums);

    return 0;
}



