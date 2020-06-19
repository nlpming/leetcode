//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1 || k >= nums.size() || k <= 0)
            return false;

        // 滑动窗口不一定是两个指针
        set<int> record;
        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) != record.end())
                return true;

            record.insert(nums[i]);
            if(record.size() == k+1)
                record.erase(nums[i-k]); // 注意此处删除nums[i-k]
        }
    }
};

int main(){
    vector<int> nums={1,2,3,1};
    int k = 3;

    cout<<Solution().containsNearbyDuplicate(nums, k)<<endl;

    return 0;
}



