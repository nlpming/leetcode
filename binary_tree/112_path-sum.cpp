//
// Created by 陈志明 on 2021/8/28.
//

/*
 * 考点：递归、二叉树、广度优先搜索；
 * 难度：*
 * */
class Solution {
public:
    //方法一：递归实现
    bool hasPathSum_one(TreeNode* root, int targetSum) {
        //NOTE: 注意递归终止条件
        if(root == NULL)
            return false;

        //NOTE: 判断是否叶子结点
        else if(root->left == NULL && root->right == NULL && root->val == targetSum){
            return true;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }

    //方法二：广度优先搜索 + 队列
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;

        queue<pair<TreeNode*, int>> record;
        record.push(make_pair(root, targetSum));

        while(!record.empty()){
            int size = record.size();
            for(int i = 0; i < size; i++){
                TreeNode *node = record.front().first;
                int val = record.front().second;
                record.pop();

                //找到路径，必须是叶子结点；
                if(node->val == val && node->left == NULL && node->right == NULL)
                    return true;

                if(node->left != NULL)
                    record.push(make_pair(node->left, val - node->val));
                if(node->right != NULL)
                    record.push(make_pair(node->right, val - node->val));
            }
        }

        return false;
    }
};