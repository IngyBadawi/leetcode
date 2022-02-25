class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        m = (int)grid.size();
        n = (int)grid[0].size();
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int vis[320][320];
    int n, m;
    
    bool notValid(int r, int c) {
        return (r >= m || r < 0 || c < 0 || c >= n);
    }
    
    void dfs(int r, int c, vector<vector<char>> &grid) {
        if(notValid(r, c) || vis[r][c] || grid[r][c] != '1')
            return;
        vis[r][c] = 1;
        for (int i = 0 ; i < 4 ; i++) {
            dfs(r + dr[i], c + dc[i], grid);
        }
    }
    
};