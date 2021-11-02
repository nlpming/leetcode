//
// Created by 陈志明 on 2021/8/30.
//

/*
 * 考点：回溯；
 * 难度：****
 * */
class Solution {
public:
    vector<vector<string>> res;
    vector<bool> visited; //列是否被访问；
    vector<bool> ldiag; //left斜对角是否被访问；row+col
    vector<bool> rdiag; //right斜对角是否被访问；n-1+row-col

    void helper(int n, int row, vector<string>& tmp){
        if(row == n){ //找到答案；
            res.push_back(tmp);
            return;
        }

        //NOTE：尝试在col=[0,...,n-1]列放置皇后；
        for(int col = 0; col < n; col++){
            if(visited[col] || ldiag[row+col] || rdiag[n-1+row-col])
                continue;

            tmp[row][col] = 'Q';
            visited[col] = ldiag[row+col] = rdiag[n-1+row-col] = true;
            helper(n, row+1, tmp); //尝试在row+1行放置皇后；
            tmp[row][col] = '.';
            visited[col] = ldiag[row+col] = rdiag[n-1+row-col] = false;
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string(n, '.'));
        visited = vector<bool>(n, false);
        ldiag = vector<bool>(2*n-1, false);
        rdiag = vector<bool>(2*n-1, false);

        //NOTE: 从第row=0行开始尝试放置皇后；
        helper(n, 0, tmp);
        return res;
    }
};