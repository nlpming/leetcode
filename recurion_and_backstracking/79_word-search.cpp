//
// Created by 陈志明 on 2021/8/30.
//

/*
 * 考点：回溯，深度优先搜索；
 * 难度：***
 * */
class Solution {
public:
    vector<vector<bool>> visited; //是否被访问；
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    //NOTE: 从位置(x,y)开始搜索；index -> 比较第几个字符；
    void helper(vector<vector<char>>& board, string word, int x, int y, int index, bool& flag){
        int m = board.size(), n = board[0].size();
        //（1）边界判定；（2）是否被访问；（3）比较的位置是否越界；（4）当前比较字符是否相等；
        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || index >= word.size() || board[x][y] != word[index])
            return;

        // 找到答案
        if(index == word.size()-1 && word[index] == board[x][y]){
            flag = true;
            return;
        }

        visited[x][y] = true; //记录已被访问；
        for(int k = 0; k < 4; k++){
            int new_x = x + directions[k][0];
            int new_y = y + directions[k][1];
            helper(board, word, new_x, new_y, index+1, flag);
        }
        visited[x][y] = false;

        return;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;

        int m = board.size(), n = board[0].size();
        bool flag = false;
        visited = vector<vector<bool>>(m, vector<bool>(n, false)); //二维数组初始化；

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //NOTE: flag传入引用；
                helper(board, word, i, j, 0, flag);
                if(flag) return true;
            }
        }

        return false;
    }
};