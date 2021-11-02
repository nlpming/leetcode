//
// Created by 陈志明 on 2021/8/30.
//

/*
 * 考点：回溯；
 * 难度：**
 * */
class Solution {
public:
    /*
     * 即求解C(n,k)问题；
     * */
    vector<vector<int>> res;
    void helper(int n, int k, int startNum, vector<int>& tmp){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }

        //解题思路：
        //1. 从startNum开始搜索新的元素；
        //2. tmp用于记录中间结果；
        //3. 剪枝优化：[i...n]必须有k - tmp.size()个元素； n-i+1 = k-tmp.size();  => i = n-(k-tmp.size())+1

        for(int i = startNum; i <= n-(k-tmp.size())+1; i++){  //NOTE: 【注意此处的剪枝优化；】
            tmp.push_back(i);
            helper(n, k, i+1, tmp); //NOTE: i=1 , 处理2，3，4
            tmp.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        helper(n, k, 1, tmp);

        return res;
    }
};