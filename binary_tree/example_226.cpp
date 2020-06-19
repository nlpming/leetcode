//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 题目描述：翻转二叉树
 * 考点：二叉树
 * 是否做出：是
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;

        // 分别反转左右子树
        invertTree(root->left);
        invertTree(root->right);

        // 交换左右子树
        swap(root->left, root->right);
        return root;
    }
};

int main() {
    vector<string> nums = {"1","2","4","null","null","5","7","null","null","null","3","null","6"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    root = Solution().invertTree(root);
    printVector(preorderTraversal(root));

    return 0;
}