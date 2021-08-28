//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：深度优先搜索；
 * 难度：**
 * */
class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode *node, int targetSum, vector<int>& tmp){
        if(node == NULL)
            return;

        tmp.push_back(node->val);
        //NOTE: 注意此处不应该直接返回；
        if(node->val == targetSum && node->left == NULL && node->right == NULL){
            res.push_back(tmp);
        }

        helper(node->left, targetSum - node->val, tmp);
        helper(node->right, targetSum - node->val, tmp);

        tmp.pop_back(); //NOTE: 注意此处回溯过程；
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return res;

        vector<int> tmp;
        dfs(root, targetSum, tmp);
        return res;
    }
};