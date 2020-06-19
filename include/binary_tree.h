//
// Created by 陈志明 on 2020/5/19.
//
#ifndef WORKSPACE_BINARY_TREE_H
#define WORKSPACE_BINARY_TREE_H

#include <vector>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(stack<string>& nums_stack){
    if(!nums_stack.empty()){
        string top = nums_stack.top();
        nums_stack.pop();

        if(top != "null"){
            TreeNode *root = new TreeNode(stoi(top));
            root->left = createTree(nums_stack);
            root->right = createTree(nums_stack);
            return root;
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}

/**
 * 先序遍历，创建二叉树
 * @param nums
 * @return
 */
TreeNode* createBinaryTree(vector<string> nums){
    if(nums.size() == 0)
        return NULL;

    // 数据存入栈中
    stack<string> nums_stack;
    for(int i=nums.size()-1; i>=0; i--){
        nums_stack.push(nums[i]);
    }

    // 递归构建二叉树
    TreeNode *root = createTree(nums_stack);
    return root;
}


void preorderProcess(TreeNode *root, vector<int> &res){
    if(root){
        res.push_back(root->val);
        preorderProcess(root->left, res);
        preorderProcess(root->right, res);
    }
}

/**
 * 二叉树先序遍历
 * @param root
 * @return
 */
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorderProcess(root, res);

    return res;
}



#endif //WORKSPACE_BINARY_TREE_H
