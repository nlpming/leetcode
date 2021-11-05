//
// Created by 陈志明 on 2021/8/26.
//

/*
 * 考点：二叉树、中序遍历、栈；
 * 难度：**
 * */
class Solution {
public:
    vector<int> res;
    void helper(TreeNode *root){
        if(root == NULL)
            return;

        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }

    //方法一：中序遍历递归实现；
    vector<int> inorderTraversal_m1(TreeNode* root) {
        helper(root);
        return res;
    }

    struct Command{
        string cmd;
        TreeNode *node;
        Command(string cmd, TreeNode *node): cmd(cmd), node(node){}
    };

    //方法二：中序遍历非递归实现；
    vector<int> inorderTraversal(TreeNode* root) {
        stack<Command> record;
        record.push(Command("go", root));
        vector<int> res;

        //root为空的情况
        if(root == NULL) return res;

        while(!record.empty()){
            Command cmd = record.top();
            record.pop();

            //打印元素值；
            if(cmd.cmd == "print")
                res.push_back(cmd.node->val);
            else{
                //栈中存放：go,right -> print,root -> go,left;
                if(cmd.node->right != NULL)
                    record.push(Command("go", cmd.node->right));
                record.push(Command("print", cmd.node));
                if(cmd.node->left != NULL)
                    record.push(Command("go", cmd.node->left));
            }
        }

        return res;
    }
};