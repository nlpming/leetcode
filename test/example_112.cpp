//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include "binary_tree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;

        // 到达叶子结点
        if(root->left == NULL && root->right == NULL)
            return root->val == sum;

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


int main(){


    return 0;
}
