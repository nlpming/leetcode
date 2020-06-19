//
// Created by 陈志明 on 2020/6/7.
//

#include <iostream>
#include <vector>
#include "print.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 设置对撞指针：left从左向右移动，right从右向左移动；
        int left = 0, right = numbers.size()-1;
        int sum_val = 0;
        vector<int> res;

        while(left < right){
            sum_val = numbers[left] + numbers[right];
            if(sum_val == target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(sum_val > target)
                right--;
            else
                left++;
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