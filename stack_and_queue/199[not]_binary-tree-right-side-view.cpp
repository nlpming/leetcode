//
// Created by 陈志明 on 2021/8/27.
//

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;

        //层次遍历；
        queue<TreeNode*> record;
        record.push(root);

        while(!record.empty()){
            int size = record.size(); //NOTE: 当前层大小；
            for(int i = 0; i < size; i++){
                TreeNode *node = record.front(); record.pop();
                if(node->left != NULL)
                    record.push(node->left);
                if(node->right != NULL)
                    record.push(node->right);

                //NOTE：当前层最后一个结点；
                if(i == size -1)
                    res.push_back(node->val);
            }
        }
        return res;
    }
};