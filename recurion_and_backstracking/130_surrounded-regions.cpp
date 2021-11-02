//
// Created by 陈志明 on 2021/8/30.
//

/*
 * 考点：深度优先搜索；
 * 难度：**
 * */
class Solution {
public:
    int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(vector<vector<char>>& board, int x, int y){
        int m = board.size(), n = board[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            return;

        //改变O -> '-'
        board[x][y] = '-';

        int new_x, new_y;
        for(int k = 0; k < 4; k++){
            new_x = x + directions[k][0];
            new_y = y + directions[k][1];
            dfs(board, new_x, new_y);
        }

        return;
    }

    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;

        //解题思路：
        //1. 首先对四周的O，进行深度优先搜索把 O -> -；
        //2. 然后遍历矩阵中的元素，把O变成X，把-变成O；

        int m = board.size(), n = board[0].size();
        //左右边界由O -> '-'
        for(int i = 0; i < m; i++){
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        //上下边界由O -> '-'
        for(int j = 0; j < n; j++){
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        //遍历矩阵：O -> X, - -> O；
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }
};