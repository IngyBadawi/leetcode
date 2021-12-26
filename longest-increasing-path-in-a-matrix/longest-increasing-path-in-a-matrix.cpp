class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        int res = 0;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                int curr = dfs(i, j, matrix, dp);
                res = max(res, curr);
            }
        }
        return res;
    }
    
private:
    bool valid_point(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }
    
    bool greater(int old_r, int old_c, int new_r, int new_c, vector<vector<int>> &matrix) {
        return matrix[new_r][new_c] > matrix[old_r][old_c];
    }
    
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        int m = matrix.size(), n = matrix[0].size();
        
        if (dp[r][c] > 0)
            return dp[r][c];
        
        //           R  D   L  U
        int dr[4] = {0, 1, -1, 0};
        int dc[4] = {1, 0, 0, -1};
        int ans = 1;
        
        for (int i = 0 ; i < 4 ; i++) {
            int new_r = r + dr[i], new_c = c + dc[i];
            if (valid_point(new_r, new_c, m, n) && greater(r, c, new_r, new_c, matrix)) {
                ans = max(ans, 1 + dfs(new_r, new_c, matrix, dp));
            }
        }
        return dp[r][c] = max(dp[r][c], ans);
    }
};