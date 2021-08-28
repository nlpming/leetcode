//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = INT_MAX, right = INT_MAX;

        //NOTE: 注意左孩子或者右孩子为NULL的情况；
        if(root->left == NULL && root->right != NULL)
            left = minDepth(root->right);
        else if(root->right == NULL && root->left != NULL)
            right = minDepth(root->left);
        else{
            left = minDepth(root->right);
            right = minDepth(root->left);
        }

        return min(left, right) + 1;
    }
};