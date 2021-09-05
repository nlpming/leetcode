//
// Created by 陈志明 on 2021/9/2.
//

class Solution {
public:
    vector<int> helper(TreeNode *node){
        vector<int> res;
        if(node == NULL)
            return {0,0};

        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);

        //NOTE: res存两个值
        //1. 第一个值，表示不偷当前结点；
        //2. 第二个值，表示偷当前结点；

        //偷取node
        int res1 = node->val + left[0] + right[0];
        //不偷取node
        int res2 = max(left[0], left[1]) + max(right[0], right[1]);

        res.push_back(res2);
        res.push_back(res1);
        return res;
    }

    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
};