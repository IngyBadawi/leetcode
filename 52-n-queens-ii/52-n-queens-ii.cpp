class Solution {
public:
    int totalNQueens(int n) {
        vector<string> grid = init(n);
        return solve(0, 0, grid);
    }
    
private:
    int solve(int row, int col, vector<string> &grid) {
        int n = grid.size();
        if (row == n) 
            return 1;
        
        if (!valid_point(row, col, n))
            return 0;
        
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            grid[row][i] = 'Q';
            if (non_attacking(grid, row, i))
                ans += solve(row + 1, i, grid);
            grid[row][i] = '.';
        }
        return ans;
    }
    
    bool valid_point(int row, int col, int n) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    
    bool non_attacking(vector<string> &grid, int r, int c) {
        int n = grid.size();
        
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            if (grid[r][i] == 'Q')
                cnt++;
        }
        if (cnt != 1)
            return false;
        
        cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            if (grid[i][c] == 'Q')
                cnt++;
        }
        if (cnt != 1)
            return false;
        
        // Check diagonals
        int dr[4] = {-1, 1, 1, -1};
        int dc[4] = {1, 1, -1, -1};
        
        for (int i = r ; i < n ; i++) {
            for (int j = c ; j < n ; j++) {
                if (grid[i][j] == 'Q') {
                    for (int k = 0 ; k < 4 ; k++) {
                        int new_r = i + dr[k];
                        int new_c = j + dc[k];
                        while(valid_point(new_r, new_c, n)) {
                            if (grid[new_r][new_c] == 'Q')
                                return false;
                            new_r = new_r + dr[k];
                            new_c = new_c + dc[k];
                        }
                    }
                }
            }
        }
        return true;
    }
    
    vector<string> init(int n) {
        string row (n, '.');
        vector<string> empty_grid(n);
        for (int i = 0 ; i < n ; i++) {
            empty_grid[i] = row;
        }
        return empty_grid;
    }
};