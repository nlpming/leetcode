//
// Created by 陈志明 on 2020/5/23.
//
#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "print.h"
using namespace std;

/**
 * 题目描述：相同的树
 * 考点：二叉树
 * 是否做出：是
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p != NULL && q != NULL) {
            if(p->val == q->val){
                // 继续比较左右子结点
                if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
};

int main() {
    vector<string> nums_p = {"1","2","null","null","3"};
    TreeNode *p = createBinaryTree(nums_p);
    vector<string> nums_q = {"1","2","null","null","3"};
    TreeNode *q = createBinaryTree(nums_q);

    printVector(preorderTraversal(p));
    printVector(preorderTraversal(q));

    cout<<Solution().isSameTree(p, q)<<endl;



    return 0;
}