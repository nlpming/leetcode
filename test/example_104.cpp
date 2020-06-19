//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include "binary_tree.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        return max(maxDepth(root->left)+1,
                   maxDepth(root->right)+1);
    }
};

int main(){


    return 0;
}

