//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、平衡二叉树；
 * 难度：*
 * */
class Solution {
public:
    int helper(TreeNode *root){
        if(root == NULL)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        return max(left, right)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;

        int left = helper(root->left);
        int right = helper(root->right);

        //注意：
        // （1）先判断当前树是否平衡二叉树；
        // （2）然后判断左子树、右子树是否平衡二叉树；

        if(abs(left - right) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }
};