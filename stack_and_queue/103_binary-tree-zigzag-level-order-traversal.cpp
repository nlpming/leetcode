//
// Created by 陈志明 on 2021/8/27.
//

/*
 * 考点：队列，广度优先搜索；
 * 难度：**
 * */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> record;
        record.push(root);

        int level = 0;
        vector<vector<int>> res;
        while(!record.empty()){
            int size = record.size();
            vector<int> tmp;

            for(int i = 0; i < size; i++){
                TreeNode *node = record.front();
                tmp.push_back(node->val);
                record.pop();

                if(node->left != NULL)
                    record.push(node->left);
                if(node->right != NULL)
                    record.push(node->right);
            }

            //根据奇偶层级做不同的判断；
            if(level%2 == 0)
                res.push_back(tmp);
            else{
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }

            //层级+1
            level += 1;
        }

        return res;
    }
};