//
// Created by 陈志明 on 2020/5/24.
//
#include <iostream>
#include <vector>
#include "print.h"
#include "binary_tree.h"

using namespace std;

/**
 * 题目描述：路径总和
 * 考点：二叉树、深度优先搜索
 * 是否做出：是
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;

        // 左右子树都为空，到达根结点
        if(root->left == NULL && root->right == NULL)
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().hasPathSum(root, 7);

    return 0;
}