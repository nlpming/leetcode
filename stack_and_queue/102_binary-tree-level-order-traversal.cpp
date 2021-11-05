//
// Created by 陈志明 on 2021/8/27.
//

class Solution {
public:
    //方法一：队列中存放level信息；
    vector<vector<int>> levelOrder_m1(TreeNode* root) {
        queue<pair<int, TreeNode*>> record; //NOTE: 队列中存放（level+1, TreeNode*）
        vector<vector<int>> res;
        if(root == NULL) return res;

        //NOTE: 插入头结点；
        record.push(make_pair(0, root));
        while(!record.empty()){
            int level = record.front().first;
            TreeNode *front = record.front().second;
            record.pop();

            if(level == res.size()){ //NOTE:注意此处的处理
                vector<int> tmp;
                tmp.push_back(front->val);

                res.push_back(tmp);
            }else{
                res[level].push_back(front->val);
            }

            if(front->left != NULL)
                record.push(make_pair(level+1, front->left));
            if(front->right != NULL)
                record.push(make_pair(level+1, front->right));
        }

        return res;
    }

    //方法二：队列中不存放level信息；
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> record;
        record.push(root);

        vector<vector<int>> res;
        while(!record.empty()){
            int size = record.size();
            vector<int> tmp;

            //获取每一层的元素；
            for(int i = 0; i < size; i++){
                TreeNode *node = record.front();
                tmp.push_back(node->val);
                record.pop();

                if(node->left != NULL)
                    record.push(node->left);
                if(node->right != NULL)
                    record.push(node->right);
            }

            res.push_back(tmp);
        }

        return res;
    }
};


