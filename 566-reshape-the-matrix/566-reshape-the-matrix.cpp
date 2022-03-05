class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int> (c));
        int curr_row = 0, curr_col = 0;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (curr_col == c) {
                    curr_row++;
                    curr_col = 0;
                }
                ans[curr_row][curr_col++] = mat[i][j];
            }
        }
        return ans;
    }
};