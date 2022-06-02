class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> transpose(n, vector<int> (m));
        for (int i = 0 ; i < m ; i++) 
            for (int j = 0 ; j < n ; j++) 
                transpose[j][i] = matrix[i][j];
            
        return transpose;
    }
};