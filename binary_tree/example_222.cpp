//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "print.h"

using namespace std;

/**
 * 题目描述：完全二叉树结点个数
 * 考点：二叉树
 * 是否做出：是
 */
class Solution {
public:
    void countProcess(TreeNode *root, vector<int>& nums){
        if(root){
            nums.push_back(root->val);
            if(root->left)
                countProcess(root->left, nums);
            if(root->right)
                countProcess(root->right, nums);
        }
    }

    int countNodes(TreeNode* root) {
        vector<int> res;
        // 对二叉树进行遍历
        countProcess(root, res);

        return res.size();
    }
};


int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().countNodes(root)<<endl;

    return 0;
}