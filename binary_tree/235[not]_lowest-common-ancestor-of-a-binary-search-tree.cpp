//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        //NOTE: （1）root处理p,q之间；（2）root=p, q (3) root=q, p;
        return root;
    }
};