//
// Created by 陈志明 on 2021/9/13.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> record;
    void helper(TreeNode *root){
        if(root == NULL)
            return;

        record.push_back(root);
        helper(root->left);
        helper(root->right);
    }

    //方法一：递归实现
    //时间复杂度：O(n)
    //空间复杂度：O(n)
    void flatten_one(TreeNode* root) {

        //先序遍历二叉树；
        helper(root);

        TreeNode *node = root;
        for(int i = 1; i < record.size(); i++){
            node->right = record[i];
            node->left = NULL;
            node = record[i]; //node结点在移动
        }

        return;
    }

    //方法二：迭代实现
    //时间复杂度：O(n)
    //空间复杂度：O(1)
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while(cur != NULL){
            //处理左子树；
            if(cur->left != NULL){
                TreeNode *next = cur->left;
                TreeNode *pre = next;
                while(pre->right != NULL){ //遍历得到next，最右边的叶子结点；
                    pre = pre->right;
                }

                //改变指针指向；
                pre->right = cur->right;
                cur->left = NULL;
                cur->right = next;
            }

            cur = cur->right;
        }
    }
};