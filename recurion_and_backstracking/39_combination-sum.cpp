//
// Created by 陈志明 on 2021/8/30.
//

/*
 * 考点：回溯、深度优先搜索；
 * 难度：***
 * */
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candidates, int target, int index, vector<int>& tmp){
        if(target == 0){ //找到答案；
            res.push_back(tmp);
            return;
        }

        //candidates元素可以重复使用；
        for(int i = index; i < candidates.size(); i++){ //NOTE: index记录开始查找的位置；【用于结果去重】
            if(target - candidates[i] < 0)
                break;

            tmp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, tmp);
            tmp.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        //candidates进行排序；
        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, tmp);
        return res;
    }
};