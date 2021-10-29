//
// Created by 陈志明 on 2021/9/13.
//

/*
 * 考点：递归、二叉树、三指针；
 * 难度：**
 * */
class Solution {
public:
    vector<TreeNode*> record;
    void preOrder(TreeNode *root){
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
        preOrder(root);
        for(int i = 0; i < record.size()-1; i++){
            record[i]->right = res[i+1];
            record[i]->left = NULL;
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