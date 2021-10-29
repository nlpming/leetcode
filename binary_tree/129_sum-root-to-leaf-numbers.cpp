//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树；
 * 难度：**
 * */
class Solution {
public:
    int res = 0;
    void helper(TreeNode *root, int number){
        if(root == NULL)
            return;

        //计算路径之和；
        number = 10 * number + root->val;
        if(root->left == NULL && root->right == NULL){
            res += number;
            return;
        }

        helper(root->left, number);
        helper(root->right, number);

        return;
    }

    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};

