//
// Created by 陈志明 on 2020/5/24.
//
#include <iostream>
#include <vector>
#include "print.h"
#include "binary_tree.h"
using namespace std;

/**
 * 题目描述：左叶子之和
 * 考点：二叉树
 * 是否做出：是
 */
class Solution {
public:
    void leftLeaves(TreeNode *root, vector<int>& nums){
        if(root == NULL)
            return;

        // 找到左叶子结点
        if(root->left){
            if(root->left->left == NULL && root->left->right == NULL){
                nums.push_back(root->left->val);
            }
        }

        leftLeaves(root->left, nums);
        leftLeaves(root->right, nums);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        vector<int> res;
        leftLeaves(root, res);

        int total = 0;
        for(int i = 0; i < res.size(); i++){
            total += res[i];
        }
        return total;
    }
};

int main() {
    vector<string> nums = {"3","9","null","null","20","15","null","null","7"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().sumOfLeftLeaves(root)<<endl;
    return 0;
}