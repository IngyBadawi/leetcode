class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    ans += dfs(i, j, grid) ? 1 : 0;
                }
            }
        }
        return ans;
    }
    
private:
    bool valid (int r, int c, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    
    bool dfs(int r, int c, vector<vector<int>> &grid) {
        if (!valid(r, c, grid))
            return false;
        if (grid[r][c] == 1)
            return true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        grid[r][c] = 1;
        
        bool ans = true;
        for (int i = 0 ; i < 4 ; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            ans &= dfs(new_r, new_c, grid);
        }
        return ans;
    }
};