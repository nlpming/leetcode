//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;

        //1.首先反转左子树，右子树中结点；
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        //2.再将左子树和右子树根结点交换；
        swap(root->left, root->right);

        return root;
    }
};