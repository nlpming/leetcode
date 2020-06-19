//
// Created by 陈志明 on 2020/5/14.
//
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 题目描述：存在重复元素II
 * 考点：集合、滑动窗口、单指针
 * 是否做出：否
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return false;

        if(k <= 0)
            return false;

        unordered_set<int> record;
        for(int i=0; i<nums.size(); i++){
            if(record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);

            // record中最多保留k个元素
            if(record.size() == k+1)
                record.erase(nums[i-k]);
        }

        return false;
    }
};

int main(){
    vector<int> nums={1,2,3,1};
    int k = 3;

    cout<<Solution().containsNearbyDuplicate(nums, k)<<endl;

    return 0;
}


