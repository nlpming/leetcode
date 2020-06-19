//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;

class Solution {
private:
    void process(TreeNode *node, string s, vector<string>& res){
        if(node == NULL)
            return;

        if(node->left == NULL && node->right == NULL)
            res.push_back(s);

        if(node->left)
            process(node->left, s+"->"+to_string(node->left->val), res);
        if(node->right)
            process(node->right, s+"->"+to_string(node->right->val), res);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;

        process(root, to_string(root->val), res);
        return res;
    }
};

int main(){


    return 0;
}