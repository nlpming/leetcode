//
// Created by 陈志明 on 2021/8/30.
//

class Solution {
public:
    //代表四个方向；
    int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    void helper(vector<vector<char>>& board, string word, int x, int y, int index, vector<vector<bool>>& visited, bool& flag){
        //1.位置不符合要求；或者已被访问；
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y]){
            return;
        }

        //2.当前字符不匹配；
        if(index >= word.size() || word[index] != board[x][y]){
            return;
        }

        //3.找到最终答案；【注意此处：index == word.size() -1】
        if(index == word.size()-1 && word[index] == board[x][y]){
            flag = true;
            return;
        }

        int new_x, new_y;
        visited[x][y] = true;
        for(int k = 0; k < 4; k++){
            new_x = x + directions[k][0];
            new_y = y + directions[k][1];
            helper(board, word, new_x, new_y, index+1, visited, flag);
        }
        visited[x][y] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;

        int m = board.size(), n = board[0].size();

        //visited数组初始化；
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool flag = false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //NOTE: 从位置i, j开始搜索；
                helper(board, word, i, j, 0, visited, flag);
                if(flag) return true;
            }
        }

        return false;
    }
};