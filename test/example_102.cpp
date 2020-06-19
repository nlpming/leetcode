//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#include "binary_tree.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;

        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));

        while(!q.empty()){
            int depth = q.front().first;
            TreeNode *node = q.front().second;
            q.pop();

            // 插入一个空数组
            if(depth == res.size())
                res.push_back({});

            res[depth].push_back(node->val);
            if(node->left)
                q.push(make_pair(depth+1, node->left));
            if(node->right)
                q.push(make_pair(depth+1, node->right));
        }

        return res;
    }
};


int main(){


    return 0;
}
