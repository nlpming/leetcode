//
// Created by 陈志明 on 2021/8/30.
//

class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int target, int index, int sum, vector<int>& tmp){
        //1. 找到答案；
        if(sum == target){
            res.push_back(tmp);
            return;
        }

        //2.大于target结束递归；
        if(sum > target){
            return;
        }

        //3. i=index注意此处去重；【每次只能从index，开始往后搜索】
        for(int i = index; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            helper(candidates, target, i, sum+candidates[i], tmp);
            tmp.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0)
            return res;

        //解题思路：
        //1. sum用于存储当前总和；
        //2. tmp用于记录中间结果；

        vector<int> tmp;

        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, tmp);
        return res;
    }
};