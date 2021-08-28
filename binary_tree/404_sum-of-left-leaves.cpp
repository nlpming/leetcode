//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left_res = 0, right_res = 0;
        //NOTE: 注意递归终止条件；
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            left_res += root->left->val;
        }else{
            left_res = sumOfLeftLeaves(root->left);
        }

        right_res = sumOfLeftLeaves(root->right);
        return left_res + right_res;
    }
};