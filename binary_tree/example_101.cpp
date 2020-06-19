//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 题目描述：对称二叉树
 * 考点：二叉树
 * 是否做出：否
 */
class Solution {
public:
    bool isValid(TreeNode *p, TreeNode *q){
        if(!p && !q) // 都等于NULL
            return true;
        else if(!p || !q) // 有一个为NULL
            return false;
        else{
            if(p->val == q->val)
                // 从此结点开始，一个往左另一个往右；或者一个往右另一个往左
                return isValid(p->left, q->right) && isValid(p->right, q->left);
            else
                return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        return isValid(root, root);
    }
};

int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().isSymmetric(root)<<endl;

    return 0;
}