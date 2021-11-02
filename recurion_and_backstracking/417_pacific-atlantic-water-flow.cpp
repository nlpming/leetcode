//
// Created by 陈志明 on 2021/8/30.
//

class Solution {
public:
    int directions[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& mark, int x, int y){
        int m = heights.size(), n = heights[0].size();

        mark[x][y] = true;
        int new_x, new_y;

        for(int k = 0; k < 4; k++){
            new_x = x + directions[k][0];
            new_y = y + directions[k][1];
            //位置不合法；
            if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
                continue;

            if(heights[new_x][new_y] >= heights[x][y] && !mark[new_x][new_y])
                dfs(heights, mark, new_x, new_y);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if(heights.size() == 0)
            return res;

        int m = heights.size(), n = heights[0].size();
        //分别记录：可以流进太平洋、大西洋的位置；
        vector<vector<bool>> pacificMark(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticMark(m, vector<bool>(n, false));

        //从四个边界开始，逆流向上寻找可以流进太平洋、大西洋的位置；
        //NOTE: 边界位置一定可以流向太平洋或者大西洋；
        for(int i = 0; i < m; i++){
            dfs(heights, pacificMark, i, 0);
            dfs(heights, atlanticMark, i, n-1);
        }
        for(int j = 0; j < n; j++){
            dfs(heights, pacificMark, 0, j);
            dfs(heights, atlanticMark, m-1, j);
        }

        //pacificMark[i][j], atlanticMark[i][j]都为true，则找到答案；
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacificMark[i][j] && atlanticMark[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};