class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        bool boundary = false;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                boundary = false;
                if (grid[i][j] && !vis[i][j]) {
                    int comp_size = dfs(i, j, grid, vis, boundary);
                    if (!boundary)
                        cnt += comp_size;
                }
            }
        }
        return cnt;
    }
    
private:
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, bool &boundary) {
        if (!valid(r, c, grid) || vis[r][c] || grid[r][c] == 0)
            return 0;
        
        if (boundary_cell(r, c, grid))
            boundary = true;
        
        vis[r][c] = 1;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        
        int sz = 1;
        
        for (int i = 0 ; i < 4 ; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            sz += dfs(new_r, new_c, grid, vis, boundary);
        }
        return sz;
    }
    
    bool valid(int r, int c, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    
    bool boundary_cell(int r, int c, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        return (r == 0 || r == m - 1 || c == 0 || c == n - 1);
    }
};