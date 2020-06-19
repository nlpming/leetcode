//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include "print.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 存放num: index
        unordered_map<int, int> record;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            if(record.find(target - nums[i]) != record.end()){
                res.push_back(record[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            else{
                record[nums[i]] = i;
            }
        }

        return res;
    }
};


int main(){
    vector<int> nums={2,7,11,15};
    int target=9;

    printVector(Solution().twoSum(nums, target));

    return 0;
}



