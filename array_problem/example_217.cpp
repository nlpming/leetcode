//
// Created by 陈志明 on 2020/5/15.
//
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 题目描述：存在重复元素
 * 考点：数组，集合
 * 是否做出：是
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record;
        for(int i=0; i<nums.size(); i++){
            if(record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int> nums={1,1,1,3,3,4,3,2,4,2};
    cout<<Solution().containsDuplicate(nums)<<endl;

    return 0;
}



