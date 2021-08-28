//
// Created by 陈志明 on 2021/8/28.
//

class Solution {
public:
    bool helper(TreeNode *node1, TreeNode *node2){
        if(node1 == NULL && node2 == NULL)
            return true;
        else if(node1 == NULL && node2 != NULL)
            return false;
        else if(node1 != NULL && node2 == NULL)
            return false;

        //NOTE: 比较node1, node2结点值是否相等；
        if(node1->val == node2->val){
            return helper(node1->left ,node2->right) && helper(node1->right, node2->left);
        }else{
            return false;
        }
    }

    //方法一：递归实现
    bool isSymmetric_one(TreeNode* root) {
        //NOTE: 将二叉树copy一份；
        return helper(root, root);
    }

    //方法二：广度优先搜索 + 队列 + visited
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;

        queue<TreeNode*> record;
        record.push(root);
        record.push(root);

        unordered_set<TreeNode*> visited; //NOTE: 记录是否已被访问；
        visited.insert(root);

        while(!record.empty()){
            //1. 每一次取出两个结点；
            TreeNode *node1 = record.front(); record.pop();
            TreeNode *node2 = record.front(); record.pop();

            if(node1 == NULL && node2 == NULL){
                continue;
            }
            else if(node1 == NULL && node2 != NULL)
                return false;
            else if(node1 != NULL && node2 == NULL)
                return false;

            //2. 每次压入两个待比较的结点；
            if(node1->val == node2->val){
                if(visited.find(node1->left) == visited.end() && visited.find(node2->right) == visited.end()){
                    record.push(node1->left);
                    record.push(node2->right);
                }

                if(visited.find(node1->right) == visited.end() && visited.find(node2->left) == visited.end()){
                    record.push(node1->right);
                    record.push(node2->left);
                }
            }else{
                return false;
            }
        }

        return true;
    }
};