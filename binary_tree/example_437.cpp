//
// Created by 陈志明 on 2020/5/25.
//
#include <iostream>
#include <vector>
#include "binary_tree.h"
#include "print.h"

using namespace std;

/**
 * 题目描述：路径总和III
 * 考点：二叉树
 * 是否做出：否
 */
class Solution {
public:
    int processOneNode(TreeNode *root, int sum){
        if(root == NULL)
            return 0;

        int res = 0;
        // 找到了和为sum的路径
        if(root->val == sum)
            res += 1;

        res += processOneNode(root->left, sum - root->val);
        res += processOneNode(root->right, sum - root->val);

        return res;
    }

    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;

        return processOneNode(root, sum) +
            pathSum(root->left, sum) +
            pathSum(root->right, sum);
    }
};


int main() {
    vector<string> nums = {"1","2","3","null","null","4","null","null","2","4","null","null","3"};
    TreeNode *root = createBinaryTree(nums);
    printVector(preorderTraversal(root));

    cout<<Solution().pathSum(root, 7)<<endl;

    return 0;
}