//
// Created by 陈志明 on 2021/8/26.
//

class Solution {
public:
    vector<int> res;

    void process(TreeNode *root){
        if(root != NULL){
            process(root->left);
            process(root->right);
            res.push_back(root->val);
        }
    }

    //方法一：递归实现；
    vector<int> postorderTraversal_one(TreeNode* root) {
        process(root);
        return res;
    }

    struct Cmd{
        string msg;
        TreeNode *node;
        Cmd(string msg, TreeNode *node): msg(msg), node(node){};
    };

    //方法二：非递归实现；
    vector<int> postorderTraversal(TreeNode *root){
        if(root == NULL) return res;
        stack<Cmd> record;

        record.push(Cmd("go", root));
        while(!record.empty()){
            Cmd top = record.top();
            record.pop();

            if(top.msg == "print"){
                res.push_back(top.node->val);
            }else{
                record.push(Cmd("print", top.node));
                if(top.node->right != NULL)
                    record.push(Cmd("go", top.node->right));
                if(top.node->left != NULL)
                    record.push(Cmd("go", top.node->left));
            }
        }

        return res;
    }

};