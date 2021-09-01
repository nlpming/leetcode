//
// Created by 陈志明 on 2021/8/30.
//

class Solution {
public:
    vector<vector<string>> res;
    vector<bool> colRecord;
    vector<bool> ldiagRecord;
    vector<bool> rdiagRecord;

    //解题思路：
    //1. 对于每一行row，尝试将皇后放在第[0...n-1]列；
    //2. 递归每一行row，尝试在[0...n-1]列放置皇后；
    //3. 初始化board为一个二维数组；
    //4. 判断行、左对角线、右对角线是否存在重复；
    //(1) 左对角线是否重复：row+col是否存在；
    //(2) 右对角线是否重复：row-col+n-1是否存在；

    void helper(int n, int row, vector<string>& board){
        //遍历到第n行，找到答案；
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            //1.已被占用；
            if(colRecord[col] || ldiagRecord[row+col] || rdiagRecord[row-col+n-1]){
                continue;
            }

            board[row][col] = 'Q';
            colRecord[col] = ldiagRecord[row+col] = rdiagRecord[row-col+n-1] = true;

            //2.递归遍历第row+1行；
            helper(n, row+1, board);

            //3.回溯过程；
            board[row][col] = '.';
            colRecord[col] = ldiagRecord[row+col] = rdiagRecord[row-col+n-1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return res;

        //ldiag判断是否重复：row+col 是否相等； rdiag判断是否重复：row-col+n-1 是否相等；
        colRecord = vector<bool>(n, false);
        ldiagRecord = vector<bool>(2*n-1, false);
        rdiagRecord = vector<bool>(2*n-1, false);

        vector<string> board(n, string(n, '.'));
        //NOTE: 从第0行开始摆放皇后；
        helper(n, 0, board);

        return res;
    }
};