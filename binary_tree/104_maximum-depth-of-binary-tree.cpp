//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树；
 * 难度：*
 * */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //NOTE: 递归终止条件
        if(root == NULL)
            return 0;

        //NOTE: 分别求左孩子、右孩子最大深度；
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right)+1;
    }
};