/*
 * 考点：回溯；
 * 难度：**
 * */
class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums, int index, vector<int>& tmp){
        //NOTE: index表示生成以Index开始的子集；
        res.push_back(tmp);
        if(index >= nums.size()){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            //NOTE: 去除重复问题；【先排序，仍后判断 nums[i] == nums[i-1] 是否成立】
            if(i > index && nums[i] == nums[i-1])
                continue;

            tmp.push_back(nums[i]);
            helper(nums, i+1, tmp);
            tmp.pop_back();
        }

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;

        sort(nums.begin(), nums.end()); //nums排序；
        helper(nums, 0, tmp);
        return res;
    }
};