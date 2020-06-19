//
// Created by 陈志明 on 2020/6/8.
//
#include <iostream>
#include "binary_tree.h"

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void process(TreeNode *root, int sum, vector<int> temp){
        if(root == NULL)
            return;

        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL && root->val == sum){
            res.push_back(temp);
            return;
        }

        if(root->left)
            process(root->left, sum - root->val, temp);
        if(root->right)
            process(root->right, sum - root->val, temp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return res;

        vector<int> temp;
        process(root, sum, temp);

        return res;
    }
};

int main(){


    return 0;
}

