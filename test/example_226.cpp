//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <utility>
#include "binary_tree.h"


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main(){


    return 0;
}