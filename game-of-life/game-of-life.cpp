class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> copy = board;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                board[i][j] |= (get_next_state(i, j, board) << 1);
            }
        }
        for (int i = 0 ; i < m ; i++)
            for (int j = 0 ; j < n ; j++)
                board[i][j] = board[i][j] >> 1;
    }
private:
    int get_next_state(int r, int c, vector<vector<int>> &board) {
        // Time: O(mxn)
        // Space: O(1) - New states are embedded in the 2nd bit and then the whole board is shifted to the right to remove the old state of the board
                //   UL   U  UR  L  R   DL D DR
        int dr[8] = {-1, -1, -1, 0, 0,  1, 1, 1};
        int dc[8] = {-1,  0,  1,-1, 1, -1, 0, 1};
        int living = 0;
        for (int i = 0 ; i < 8 ; i++) {
            int new_r = r + dr[i], new_c = c + dc[i];
            if (valid(new_r, new_c, board))
                living += board[new_r][new_c] & 1;
        }
        return next_state(board[r][c] & 1, living);
    }
    
    bool valid(int r, int c, vector<vector<int>> &board) {
        int m = board.size(), n = board[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
    
    int next_state(int living_cell, int living_neighbours) {
        if (living_cell && living_neighbours < 2)
            return 0;
        if (living_cell && (living_neighbours == 2 || living_neighbours == 3))
            return 1;
        if (living_cell && living_neighbours > 3)
            return 0;
        if (!living_cell && living_neighbours == 3)
            return 1;
        return living_cell;
    }
    
};