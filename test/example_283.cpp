//
// Created by 陈志明 on 2020/6/9.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1)
            return;

        // 注意：left,right的初始值
        int left = -1, right = 0;
        while(right < nums.size()){
            if(nums[right] != 0){
                left++;
                if(left != right)
                    swap(nums[left], nums[right]);
                right++;
            }
            else
                right++;
        }
    }
};

int main(){
    vector<int> nums = {1, 0};
    printVector(nums);
    Solution().moveZeroes(nums);
    printVector(nums);

    return 0;
}

