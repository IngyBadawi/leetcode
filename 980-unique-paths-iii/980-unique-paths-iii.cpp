class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int st_row, ed_row, st_col, ed_col;
        int m = grid.size(), n = grid[0].size();
        
        // Get starting and ending positions
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1)
                    st_row = i, st_col = j;
                else if (grid[i][j] == 2)
                    ed_row = i, ed_col = j;
            }
        }
        
        int ans = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        dfs(vis, grid, st_row, st_col, ed_row, ed_col, ans);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>> &vis, vector<vector<int>> &grid, int r, int c, int ed_row, int ed_col, int &ans) {
        int m = grid.size(), n = grid[0].size();
        if (r == ed_row && c == ed_col) {
            if (all_non_obstacles_visited(vis, grid))
                ans += 1;
            return;
        }
//                   L  R   U  D
        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};
        vis[r][c] = 1;
        for (int i = 0 ; i < 4 ; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            if (valid(new_r, new_c, m, n, grid) && !vis[new_r][new_c]) {
                dfs(vis, grid, new_r, new_c, ed_row, ed_col, ans);
            }
        }
        vis[r][c] = 0;
    }
    
    bool valid(int r, int c, int m, int n, vector<vector<int>> &grid) {
        return (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != -1);
    }
    
    bool all_non_obstacles_visited(vector<vector<int>> &vis, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
};