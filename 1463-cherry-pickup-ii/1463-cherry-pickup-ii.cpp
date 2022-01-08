class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp (m, vector<vector<int>> (n, vector<int>(n, -1)));
        return solve(0, 0, n - 1, grid, dp);
    }

private:
    int solve(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if (!valid_cols(c1, c2, grid))
            return -1e9;
        if (r == grid.size())
            return 0;
        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int dc[3] = {-1, 0, 1};
        int ans = -1e9;
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                int curr = grid[r][c1] + grid[r][c2] - grid[r][c1] * (c1 == c2);
                ans = max(ans, curr + solve(r + 1, c1 + dc[i], c2 + dc[j], grid, dp));
            }
        }
        return dp[r][c1][c2] = ans;
    }
    
    bool valid_cols(int c1, int c2, vector<vector<int>> &grid) {
        int n = grid[0].size();
        return (c1 >= 0 && c1 < n && c2 >= 0 && c2 < n);
    }
};