/*
 * 考点：深度优先搜索；
 * 难度：**
 * */
class Solution {
public:
    int directions[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<char>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        //（1）当前位置不合法；（2）当前位置值不为1；
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
            return;

        grid[x][y] = '0';
        int new_x, new_y;
        for(int k = 0; k < 4; k++){
            new_x = x + directions[k][0];
            new_y = y + directions[k][1];
            dfs(grid, new_x, new_y);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;

        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){ //当前为1，进行深度优先搜索将1置为0；
                    res += 1;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};