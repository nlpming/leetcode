//
// Created by 陈志明 on 2021/8/29.
//

/*
 * 考点：回溯，深度优先搜索；
 * 难度：***
 * */
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;
    void helper(vector<int>& nums, int index, vector<int>& tmp){
        if(index == nums.size()){
            res.push_back(tmp);
            return;
        }

        //每次都是从 0 -> n-1;
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] || (i > 0 && nums[i] == nums[i-1] && visited[i-1])) //NOTE: 注意此处去重；
                continue;

            tmp.push_back(nums[i]);
            visited[i] = true;
            helper(nums, index+1, tmp); //index代表处理，第几个数字；
            tmp.pop_back(); //NOTE: 回溯过程；
            visited[i] = false;
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        //NOTE: 首先对nums排序；
        sort(nums.begin(), nums.end());

        int n = nums.size();
        visited = vector<bool>(n, false); //visited初始化；

        vector<int> tmp;
        helper(nums, 0, tmp);
        return res;
    }
};