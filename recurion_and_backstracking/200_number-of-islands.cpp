/*
 * 考点：深度优先搜索；
 * 难度：**
 * */
class Solution {
public:
    int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(vector<vector<char>>& grid, int x, int y){
        //1.当前位置不合法；
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()){
            return;
        }

        //2.当前元素不为1；
        if(grid[x][y] != '1'){
            return;
        }

        grid[x][y] = '0'; //把x,y开始周围的1全部置为0；使用深度优先搜索算法；
        int new_x, new_y;
        for(int k = 0; k < 4; k++){
            new_x = x + directions[k][0];
            new_y = y + directions[k][1];
            dfs(grid, new_x, new_y);
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int res = 0;

        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};