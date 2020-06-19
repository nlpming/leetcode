//
// Created by 陈志明 on 2020/5/15.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/**
 * 题目描述：存在重复元素III
 * 考点：滑动窗口，有序查找表
 * 是否做出：否
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> record;

        for(int i=0; i<nums.size(); i++){
            // 查找的元素在[nums[i]-t, nums[i]+t]之间；查找表是有序的；
            // lower_bound 返回第一个大于等于x的iterator
            if(record.lower_bound((long)nums[i] - (long)t) != record.end() &&
                *record.lower_bound((long)nums[i] - (long)t) <= (long)nums[i] + (long)t)
                return true;

            record.insert(nums[i]);
            if(record.size() == k+1)
                record.erase(nums[i-k]);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    int k = 3, t = 0;

    cout<<Solution().containsNearbyAlmostDuplicate(nums, k, t)<<endl;

    return 0;
}

