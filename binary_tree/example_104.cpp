//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include <string>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 题目描述：二叉树最大深度
 * 考点：二叉树、递归
 * 是否做出：是
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};


int main() {
    vector<string> nums = {"1","2","4","null","null","5","7","null","null","null","3","null","6"};
    TreeNode *root = createBinaryTree(nums);

    printVector(preorderTraversal(root));
    cout<<Solution().maxDepth(root)<<endl;


    return 0;
}