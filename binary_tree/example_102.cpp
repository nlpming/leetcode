//
// Created by 陈志明 on 2020/5/20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 题目描述：二叉树的层次遍历
 * 考点：队列、广度优先搜索
 * 是否做出：是
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 队列中存放：（int level, TreeNode *node）
        queue<pair<int, TreeNode*>> tq;
        vector<vector<int>> res;

        if(root == NULL)
            return res;

        tq.push(make_pair(0, root));
        while(!tq.empty()){
            int level = tq.front().first;
            TreeNode *node = tq.front().second;
            // 二维空数组的处理
            if(level == res.size())
                res.push_back({});
            res[level].push_back(node->val);

            tq.pop();

            if(node->left)
                tq.push(make_pair(level+1, node->left));

            if(node->right)
                tq.push(make_pair(level+1, node->right));
        }

        return res;
    }
};


int main() {
    vector<string> nums = {"3", "9", "null", "null", "20", "15", "null", "null", "7"};
    TreeNode *root = createBinaryTree(nums);

    vector<vector<int>> res = Solution().levelOrder(root);

    for(int i=0; i<res.size(); i++)
        printVector(res[i]);

    return 0;
}