//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    vector<string> res;
    void helper(TreeNode *node, string tmp){
        //NOTE: 注意递归终止条件；
        if(node->left == NULL && node->right == NULL){
            res.push_back(tmp);
            return;
        }

        string left_tmp = tmp, right_tmp = tmp;
        if(node->left != NULL){
            left_tmp += "->" + to_string(node->left->val);
            helper(node->left, left_tmp);
        }

        if(node->right != NULL){
            right_tmp += "->" + to_string(node->right->val);
            helper(node->right, right_tmp);
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return res;

        string tmp(to_string(root->val));
        helper(root, tmp);
        return res;
    }
};