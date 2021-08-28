//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left_nums = countNodes(root->left);
        int right_nums = 0;

        //NOTE: 判断右孩子是否为NULL；
        if(root->right != NULL)
            right_nums = countNodes(root->right);

        return left_nums+right_nums+1;
    }
};


