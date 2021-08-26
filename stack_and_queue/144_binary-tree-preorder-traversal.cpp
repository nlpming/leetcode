//
// Created by 陈志明 on 2021/8/26.
//

class Solution {
public:
    vector<int> res;
    void process(TreeNode *root){
        if(root != NULL){
            res.push_back(root->val);
            process(root->left);
            process(root->right);
        }
    }

    //方法一：递归实现；
    vector<int> preorderTraversal_one(TreeNode* root) {
        process(root);
        return res;
    }

    //方法二：使用栈，实现非递归；
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> record;

        if(root == NULL) return res;
        record.push(root);

        while(!record.empty()){
            //NOTE: 取出当前结点，并加入val到res中；
            TreeNode *top = record.top();
            record.pop();
            res.push_back(top->val);

            //NOTE: 如果当前结点left, right结点不为NULL；则将其加入stack中；【注意：先加入right结点，然后加入left】
            if(top->right != NULL)
                record.push(top->right);
            if(top->left != NULL)
                record.push(top->left);
        }

        return res;
    }
};