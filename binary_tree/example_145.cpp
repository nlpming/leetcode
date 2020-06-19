//
// Created by 陈志明 on 2020/5/19.
//
#include <iostream>
#include <vector>
#include <cassert>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 二叉树后序遍历
 */

// 递归实现
class Solution1 {
public:
    void postorderProcess(TreeNode *node, vector<int> &res){
        if(node){
            postorderProcess(node->left, res);
            postorderProcess(node->right, res);
            res.push_back(node->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderProcess(root, res);

        return res;
    }
};

// 非递归实现
class Solution2 {
private:
    struct Command{
        string s; //go, print
        TreeNode *node;
        Command(string s, TreeNode *node): s(s), node(node) {}
    };
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return {};

        // 首先压入命令go root结点；
        stack<Command> cmd_stack;
        cmd_stack.push(Command("go", root));

        while(!cmd_stack.empty()){
            Command cmd = cmd_stack.top();
            cmd_stack.pop();

            if(cmd.s == "print"){
                res.push_back(cmd.node->val);
            }
            else{
                // 先遍历左孩子，之后遍历右孩子，打印node
                assert(cmd.s == "go");
                cmd_stack.push(Command("print", cmd.node));
                if(cmd.node->right)
                    cmd_stack.push(Command("go", cmd.node->right));
                if(cmd.node->left)
                    cmd_stack.push(Command("go", cmd.node->left));
            }
        }
        return res;
    }
};

int main() {
    vector<string> nums = {"1", "null", "2", "3"};
    TreeNode *root = createBinaryTree(nums);

    printVector(Solution2().postorderTraversal(root));

    return 0;
}