class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows = validate_rows(board);
        bool columns = validate_columns(board);
        bool boxes = validate_boxes(board);
        return (rows && columns && boxes);
    }

private:
    bool validate_rows(vector<vector<char>> &board) {
        for (int i = 0 ; i < 9 ; i++) {
            vector<bool> vis(10, false);
            for (int j = 0 ; j < 9 ; j++) {
                if (board[i][j] != '.') {
                    int current = board[i][j] - '0';
                    if (vis[current])
                        return false;
                    vis[current] = true;
                }
            }
        }
        return true;
    }
    
    bool validate_columns(vector<vector<char>> &board) {
        for (int i = 0 ; i < 9 ; i++) {
            vector<bool> vis(10, false);
            for (int j = 0 ; j < 9 ; j++) {
                if (board[j][i] != '.') {
                    int current = board[j][i] - '0';
                    if (vis[current])
                        return false;
                    vis[current] = true;
                }
            }
        }
        return true;
    }
    
    bool validate_boxes(vector<vector<char>> &board) {
        for (int i = 0 ; i < 9 ; i += 3) {
            for (int j = 0 ; j < 9 ; j += 3) {
                vector<bool> vis(10, false);
                cout<<i<<", "<<j<<endl;
                for (int k = i ; k < i + 3 ; k++) {
                    for (int l = j ; l < j + 3 ; l++) {
                        if (board[k][l] != '.') {
                            int current = board[k][l] - '0';
                            if (vis[current])
                                return false;
                            vis[current] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
    
    void print_vis(string title, vector<bool> vis) {
        cout<<title<<endl;
        for (int i = 1 ; i < 10 ; i++)
            cout<<i<<" : "<<vis[i]<<endl;
        cout<<endl;
    }
};