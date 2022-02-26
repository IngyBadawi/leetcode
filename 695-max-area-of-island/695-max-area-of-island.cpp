class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int area = 0;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                area = max(area, dfs(i, j, grid, vis));
            }
        }
        return area;
    }
    
private:
    int dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        if (!valid(r, c, grid) || vis[r][c] || grid[r][c] == 0)
            return 0;
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        vis[r][c] = 1;
        int component = 1;
        
        for (int i = 0 ; i < 4 ; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            component += dfs(new_r, new_c, grid, vis); 
        }
        
        return component;
    }
    
    bool valid(int r, int c, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
};