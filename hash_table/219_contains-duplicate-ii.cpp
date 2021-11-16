//
// Created by 陈志明 on 2021/8/24.
//

/*
 * 考点：单指针 + 一次遍历 + 哈希表
 * 难度：**
 * 时间复杂度：O(n);
 * */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> record; //数值 -> 位置；
        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) == record.end()){
                record[nums[i]] = i;
            }else{
                if(abs(i - record[nums[i]]) <= k)
                    return true;
                record[nums[i]] = i; //更新位置；
            }
        }

        return false;
    }
};