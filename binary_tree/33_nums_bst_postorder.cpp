//
// Created by 陈志明 on 2021/9/23.
//

class Solution {
public:
    bool helper(vector<int>& postorder, int left, int right){
        if(left >= right) return true;

        //1.首先划分数组；[left, mid-1], [mid, right-1], [right]
        //（1）后序遍历结果：[左子树，右子树，根结点]
        // (2) 二叉搜索树性质：根结点大于左子树所有结点的值；并且小于所有右子树结点的值；
        int p = left;
        while(postorder[p] < postorder[right])
            p++;

        int mid = p;
        while(postorder[p] > postorder[right])
            p++;

        //2.判断是否满足二叉搜索树定义；
        return p == right && helper(postorder, left, mid-1) && helper(postorder, mid, right-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        //TODO: 解题思路 https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
        return helper(postorder, 0, postorder.size()-1);
    }
};