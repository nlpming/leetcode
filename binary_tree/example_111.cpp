//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "print.h"

using namespace std;

/**
 * 题目描述：二叉树的最小深度
 * 考点：二叉树
 * 是否做出：否
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        // 注意结点，左或者右孩子为NULL的情况
        if(root->left != NULL && root->right == NULL)
            return 1 + minDepth(root->left);
        if(root->left == NULL && root->right != NULL)
            return 1 + minDepth(root->right);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};



int main() {
    vector<string> nums = {"1","2","4","null","null","5","7","null","null","null","3","null","6"};
    TreeNode *root = createBinaryTree(nums);

    printVector(preorderTraversal(root));
    cout<<Solution().minDepth(root)<<endl;

    return 0;
}