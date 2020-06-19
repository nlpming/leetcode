//
// Created by 陈志明 on 2020/5/24.
//
#include <iostream>
#include <vector>
#include <cmath>
#include "binary_tree.h"
#include "print.h"

using namespace std;

/**
 * 题目描述：求根到叶子结点数字之和
 * 考点：树，深度优先搜索
 * 是否做出：是
 */
class Solution {
public:
    void allPath(TreeNode *root, vector<int> p, vector<vector<int>>& res){
        if(root == NULL)
            return;

        // 到达根结点
        if(root->left == NULL && root->right == NULL){
            p.push_back(root->val);
            res.push_back(p);
        }

        p.push_back(root->val);
        if(root->left)
            allPath(root->left, p, res);
        if(root->right)
            allPath(root->right, p, res);
    }

    int sumNumbers(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> p;
        allPath(root, p, res);

        int total = 0;
        for(int i = 0; i < res.size(); i++){
            int temp = 0;
            int len = res[i].size();
            for(int j = len-1; j >= 0; j--){
                temp += res[i][j]*pow(10, len-1-j);
            }
            total += temp;
        }
        return total;
    }
};

int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().sumNumbers(root)<<endl;

    return 0;
}