//
// Created by 陈志明 on 2020/5/24.
//
#include <iostream>
#include <vector>
#include <string>
#include "binary_tree.h"
#include "print.h"

using namespace std;

/**
 * 题目描述：二叉树的所有路径
 * 考点：二叉树
 * 是否做出：是
 */
class Solution {
public:
    void treePaths(TreeNode *root, string s, vector<string>& res){
        // 找到一条路径
        if(root->left == NULL && root->right == NULL){
            res.push_back(s);
        }

        // s表示到当前结点的路径
        if(root->left)
            treePaths(root->left, s + "->" + to_string(root->left->val), res);
        if(root->right)
            treePaths(root->right, s + "->" + to_string(root->right->val), res);

        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;

        treePaths(root, to_string(root->val), res);
        return res;
    }
};

int main() {
    vector<string> nums = {"3","9","null","null","20","15","null","null","7"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    printVector(Solution().binaryTreePaths(root));

    return 0;
}