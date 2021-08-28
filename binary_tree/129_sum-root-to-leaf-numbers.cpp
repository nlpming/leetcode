//
// Created by 陈志明 on 2021/8/28.
//
class Solution {
public:
    int res = 0;
    void helper(TreeNode *node, int tmp){
        if(node->left == NULL && node->right == NULL){
            res += tmp;
            return;
        }

        //NOTE: 如何求和 x = x*10 + y;
        int left_val = tmp, right_val = tmp;
        if(node->left != NULL){
            left_val = 10*left_val + node->left->val;
            helper(node->left, left_val);
        }

        if(node->right != NULL){
            right_val = 10*right_val + node->right->val;
            helper(node->right, right_val);
        }

        return;
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;

        helper(root, root->val);
        return res;
    }
};


