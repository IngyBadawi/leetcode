class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid = init(n);
        vector<vector<string>> ret;
        solve(0, 0, ret, grid);
        return ret;
    }
    
private:
    void solve(int row, int col, vector<vector<string>> &ret, vector<string> &grid) {
        int n = grid.size();
        if (row == n) {
            ret.push_back(grid);
            return;
        }
        
        if (!valid_point(row, col, n))
            return;
        
        for (int i = 0 ; i < n ; i++) {
            grid[row][i] = 'Q';
            if (non_attacking(grid))
                solve(row + 1, i, ret, grid);
            grid[row][i] = '.';
        }
    }
    
    bool valid_point(int row, int col, int n) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    
    bool non_attacking(vector<string> &grid) {
        int n = grid.size();
        
        // Check rows
        for (int i = 0 ; i < n ; i++) {
            int cnt = 0;
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 'Q')
                    cnt++;
            }
            if (cnt != 1 && cnt != 0)
                return false;
        }
        
        // Check columns
        for (int i = 0 ; i < n ; i++) {
            int cnt = 0;
            for (int j = 0 ; j < n ; j++) {
                if (grid[j][i] == 'Q')
                    cnt++;
            }
            if (cnt != 1 && cnt != 0)
                return false;
        }
        
        
        // Check diagonals
        int dr[4] = {-1, 1, 1, -1};
        int dc[4] = {1, 1, -1, -1};
        
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
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