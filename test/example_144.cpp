//
// Created by 陈志明 on 2020/6/7.
//
#include <iostream>
#include <vector>
#include "binary_tree.h"

class Solution {
private:
    struct Command{
        string s; // go, print
        TreeNode *node;
        Command(string s, TreeNode *node): s(s), node(node) {}
    };
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;

        stack<Command> record;
        record.push(Command("go", root));

        while(!record.empty()){
            Command cmd = record.top();
            record.pop();

            if(cmd.s == "print"){
                res.push_back(cmd.node->val);
            }
            else{
                if(cmd.node->right)
                    record.push(Command("go", cmd.node->right));

                if(cmd.node->left)
                    record.push(Command("go", cmd.node->left));

                record.push(Command("print", cmd.node));
            }
        }

        return res;
    }
};

int main(){


    return 0;
}

