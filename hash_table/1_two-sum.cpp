//
// Created by 陈志明 on 2021/8/23.
//

/*
 * 考点：哈希表
 * 难度：**
 * */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        vector<int> res;

        //注意：
        // 1. 每次检查当前数 nums[i] 是否在record中出现；
        // 2. 如果 nums[i] 没有在record中出现，则将 {target - nums[i]，idx} 压入map中；
        // 3. 否则找到题目答案；

        for(int i = 0; i < nums.size(); i++){
            if(record.find(nums[i]) == record.end()){
                record[target-nums[i]] = i;
            }else{
                res.push_back(record[nums[i]]); //注意此处
                res.push_back(i);
                break;
            }
        }

        return res;
    }
};