//
// Created by 陈志明 on 2021/8/30.
//

/*
 * 考点：回溯；
 * 难度：**
//NOTE: index表示处理以nums[index]开始的所有子集；
// []
// 1
// 1,2
// 1,2,3
// 1,3
// 2
// 2,3
// 3
 * */
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, int index, vector<int>& tmp){
        //NOTE: 中间结果加入到res;
        res.push_back(tmp);
        if(index >= nums.size()){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            helper(nums, i+1, tmp);
            tmp.pop_back();
        }

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;

        //NOTE: index表示生成以Index开始的子集；
        helper(nums, 0, tmp);
        return res;
    }
};