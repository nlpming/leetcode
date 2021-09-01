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
                //NOTE: 【注意此处去除重复；】
                if(i > 0 && nums[i] == nums[i-1] && visited[i-1])
                    continue;

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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0)
            return res;

        vector<bool> visited(nums.size(), false); //记录是否被访问；
        vector<int> record; //记录中间结果；

        sort(nums.begin(), nums.end());
        dfs(nums, 0, record, visited);

        return res;
    }
};