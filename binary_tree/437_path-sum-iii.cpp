//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树；
 * 难度：**
 * */
class Solution {
public:
    int res = 0;

    //NOTE: 查找以node为起始结点：最后总和为targetSum的路径数量；
    void helper(TreeNode *node, int targetSum){
        if(node->val == targetSum){ //NOTE: 注意此处需要继续向下查找；
            res += 1;
        }

        if(node->left != NULL){
            helper(node->left, targetSum - node->val);
        }

        if(node->right != NULL){
            helper(node->right, targetSum - node->val);
        }

        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;

        //以当前结点作为起始结点查找；
        helper(root, targetSum);

        //遍历每一个结点；
        if(root->left != NULL){
            pathSum(root->left, targetSum);
        }
        if(root->right != NULL){
            pathSum(root->right, targetSum);
        }

        return res;
    }
};