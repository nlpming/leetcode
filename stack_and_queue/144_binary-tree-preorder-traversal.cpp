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

    //NOTE: 递归辅助结构体；
    struct Cmd{
        string msg;
        TreeNode *node;
        Cmd(string msg, TreeNode *node): msg(msg), node(node){};
    };

    //方法二：使用栈，实现非递归；
    vector<int> preorderTraversal(TreeNode* root) {
        stack<Cmd> record;
        if(root == NULL) return res;

        //NOTE: 初始访问root结点；
        record.push(Cmd("go", root));
        while(!record.empty()){
            Cmd cmd = record.top();
            record.pop();

            if(cmd.msg == "print"){
                res.push_back(cmd.node->val);
            }else{
                if(cmd.node->right != NULL)
                    record.push(Cmd("go", cmd.node->right));
                if(cmd.node->left != NULL)
                    record.push(Cmd("go", cmd.node->left));
                record.push(Cmd("print", cmd.node));
            }
        }

        return res;
    }
};