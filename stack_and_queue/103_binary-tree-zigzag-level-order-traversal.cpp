//
// Created by 陈志明 on 2021/8/27.
//

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<pair<int, TreeNode*>> record;
        record.push(make_pair(0, root));
        while(!record.empty()){
            int level = record.front().first;
            TreeNode *node = record.front().second;
            record.pop();

            if(level == res.size()){
                vector<int> tmp;
                tmp.push_back(node->val);

                res.push_back(tmp);
            }else{
                //NOTE: 相比层次遍历，主要改动的地方；
                if(level%2 == 0){
                    //偶数插入vector末尾；
                    res[level].push_back(node->val);
                }else{
                    //奇数插入vector开头；
                    res[level].insert(res[level].begin(), node->val);
                }
            }

            if(node->left != NULL)
                record.push(make_pair(level+1, node->left));
            if(node->right != NULL)
                record.push(make_pair(level+1, node->right));
        }

        return res;
    }
};