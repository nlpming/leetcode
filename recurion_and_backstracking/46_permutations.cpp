//
// Created by 陈志明 on 2021/8/29.
//

class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> nums, int index, vector<int>& record, vector<bool>& visited){
        if(index == nums.size()){
            res.push_back(record);
            return;
        }

        //NOTE: 每次i都是从[0...n-1]遍历；
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                record.push_back(nums[i]);
                visited[i] = true;

                //index: 表示处理第几个数字；
                dfs(nums, index+1, record, visited);

                record.pop_back();
                visited[i] = false;
            }
        }

        return;
    }

    //方法一：不修改nums；
    vector<vector<int>> permute_one(vector<int>& nums) {
        if(nums.size() == 0)
            return res;

        vector<bool> visited(nums.size(), false); //记录是否被访问；
        vector<int> record; //记录中间结果；
        dfs(nums, 0, record, visited);

        return res;
    }

    void helper(vector<int>& nums, int left, int right){
        if(left == right){
            res.push_back(nums);
            return;
        }

        for(int i = left; i <= right; i++){
            swap(nums[left], nums[i]);
            helper(nums, left+1, right);
            swap(nums[left], nums[i]);
        }
    }

    //方法二：直接修改nums；
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return res;

        helper(nums, 0, nums.size()-1);
        return res;
    }
};