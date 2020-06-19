//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include <cmath>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 题目描述：判断是否为平衡二叉树
 * 考点：平衡二叉树
 * 是否做出：是
 */
class Solution {
public:
    int maxDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;

        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);

        if(abs(left_max_depth-right_max_depth) <= 1)
            // 判断左右子树，是否为平衡二叉树
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }
};

int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().isBalanced(root)<<endl;

    return 0;
}