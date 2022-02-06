class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m - 1;
        vector<int> first_col(m);
        for (int i = 0 ; i < m ; i++)
            first_col[i] = matrix[i][0];
        
        int row_ind = upper_bound(first_col.begin(), first_col.end(), target) - first_col.begin() - 1;
        if (row_ind < 0)
            return false;
        int col_ind = lower_bound(matrix[row_ind].begin(), matrix[row_ind].end(), target) - matrix[row_ind].begin();
        if (col_ind >= n)
            return false;
        return matrix[row_ind][col_ind] == target;
    }
};