//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树；
 * 难度：*
 * */
class Solution {
public:
    vector<string> res;
    void helper(TreeNode *root, string tmp){
        if(root == NULL)
            return;

        //将路径串起来；
        if(tmp.size() == 0)
            tmp = to_string(root->val);
        else
            tmp += "->" + to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            res.push_back(tmp);
            return;
        }

        if(root->left != NULL)
            helper(root->left, tmp);
        if(root->right != NULL)
            helper(root->right, tmp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp = "";
        helper(root, tmp);

        return res;
    }
};