//
// Created by 陈志明 on 2020/5/24.
//
#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "print.h"

using namespace std;

/**
 * 题目描述：路径总和II
 * 考点：二叉树、深度优先搜索
 * 是否做出：是
 */
class Solution {
public:
    void process(TreeNode *root, int sum, vector<int> p, vector<vector<int>>& res){
        if(root == NULL)
            return;

        // 找到和为sum的路径
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                p.push_back(root->val);
                res.push_back(p);
            }
        }

        p.push_back(root->val);
        process(root->left, sum - root->val, p, res);
        process(root->right, sum - root->val, p, res);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> p;
        process(root, sum, p, res);

        return res;
    }
};


int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    vector<vector<int>> res = Solution().pathSum(root, 7);
    for(int i = 0; i < res.size(); i++)
        printVector(res[i]);

    return 0;
}