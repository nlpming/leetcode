//
// Created by 陈志明 on 2020/5/28.
//
#include <iostream>
#include <vector>

using namespace std;
/**
 * 题目描述：单词搜索
 * 考点：回溯算法
 * 是否做出：否
 */
class Solution {
private:
    vector<vector<bool>> visited;
    // 上右下左，四个方向分别搜索
    int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int m, n;

    bool isValid(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从坐标startx, starty开始递归搜索
    bool searchWord(const vector<vector<char>>& board, string word, int index,
            int startx, int starty){
        if(index == word.size()-1)
            return board[startx][starty] == word[index];

        if(board[startx][starty] == word[index]){
            visited[startx][starty] = true;
            for(int i = 0; i < 4; i++){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                cout<<newx<<","<<newy<<endl;

                if(isValid(newx, newy) && !visited[newx][newy] &&
                    searchWord(board, word, index+1, newx, newy))
                    return true;
            }
            // 回溯过程，四个方向都没有找到；
            visited[startx][starty] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        // 二维数组初始化
        for(int i = 0; i < m; i++)
            visited.push_back(vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(searchWord(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word = "ABCCED";


    cout << Solution().exist(board, word) << endl;


    return 0;
}