//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, right = nums.size();
        int i = 0;

        while(i < right){
            if(nums[i] == 0){
                left++;

                // 注意此处容易犯错
                if(i == left)
                    i++;
                else
                    swap(nums[i], nums[left]);
            }
            else if(nums[i] == 2){
                right--;
                swap(nums[i], nums[right]);
            }
            else{
                i++;
            }
        }
    }
};

int main(){
    vector<int> nums = {0,2,1,2,0,1,1};
    printVector(nums);

    Solution().sortColors(nums);
    printVector(nums);

    return 0;
}




