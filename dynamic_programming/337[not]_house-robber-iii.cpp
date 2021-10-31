//
// Created by 陈志明 on 2021/9/2.
//

/*
 * 考点：二叉树，动态规划；
 * 难度：***
 * */
class Solution {
public:
    vector<int> helper(TreeNode *node){
        if(node == NULL)
            return {0, 0};

        //0 -> 偷当前结点获取的最高金额；
        //1 -> 不偷当前结点获取的最高金额；【不偷当前结点，则获取的最大金额为：max(left[0], left[1]) + max(right[0], right[1])】
        if(node->left == NULL && node->right == NULL)
            return {node->val, 0};

        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);

        return {node->val + left[1] + right[1], max(left[0], left[1]) + max(right[0], right[1])};
    }

    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
};