//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树；
 * 难度：*
 * */
class Solution {
public:
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;

        //判断左叶子结点；
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            res += root->left->val;

        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);

        return res;
    }
};