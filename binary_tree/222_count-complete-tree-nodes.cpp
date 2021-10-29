//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树；
 * 难度：*
 * */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        int left_num = countNodes(root->left);
        int right_num = countNodes(root->right);

        return 1 + left_num + right_num;
    }
};


