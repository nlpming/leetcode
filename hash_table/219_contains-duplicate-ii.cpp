//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：滑动窗口 + 哈希表；
 * 难度：**
 * 时间复杂度：O(n);
 * */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;

        int left = -1, right = 0;
        unordered_set<int> record;
        record.insert(nums[0]);

        //解题思路：
        // 1. record存放(left, right]中的元素；并且record中不存在重复元素；
        // 2. 如果存在重复，则将left++, record.erase(nums[left])；并且重复元素不加入record中；
        // 3. 如果不存在重复，则right++, record.insert(nums[right])；

        while(right+1 < nums.size()){
            if(record.find(nums[right+1]) == record.end()){
                right++;
                record.insert(nums[right]);
            }else{
                left++;
                record.erase(nums[left]);

                if(nums[left] == nums[right+1] && abs(right+1-left) <= k){ //NOTE: 注意此处边界处理
                    return true;
                }
            }
        }

        return false;
    }
};