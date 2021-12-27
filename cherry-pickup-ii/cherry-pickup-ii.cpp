class Solution {
public:
    int rows, cols, dp[71][71][71];
    int dc[3] = {-1, 0, 1};
        
    int valid(pair<int, int> pos1, pair<int, int> pos2){
        return (pos1.first <= rows && pos1.second >= 0 &&
                pos1.second < cols && pos2.second >= 0 && pos2.second < cols);
    }
    
    int solve(vector<vector<int>> &grid, int r, int c1, int c2){
        if(c1 < 0 || c2 < 0 || c1 >= cols || c2 >= cols) 
            return -2e7;
        if(r == rows) 
            return 0;
        if(dp[r][c1][c2] != -1) 
            return dp[r][c1][c2];
        
        pair<int, int> pos1, pos2;
        int ans = -2e7;
        int curr = grid[r][c1] + grid[r][c2] - grid[r][c1] * (c1 == c2);
        
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                pos1 = {r + 1, c1 + dc[i]};
                pos2 = {r + 1, c2 + dc[j]};
                if(valid(pos1, pos2)){ 
                    ans = max(ans, curr + solve(grid, r + 1, pos1.second, pos2.second));
                }
            }
        }
        
        return dp[r][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        memset(dp, -1, sizeof dp);
        return solve(grid, 0, 0, cols - 1);
    }
};