class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return 0;
        
        adjust_dp(obstacleGrid, dp, 0, 1);
        adjust_dp(obstacleGrid, dp, 1, 0);
        
        for (int i = 1 ; i < m ; i++) {
            for (int j = 1 ; j < n ; j++) {
                if (!obstacleGrid[i][j])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[m - 1][n - 1];
    }
    
private:
    void adjust_dp(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int row, int col) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int sz = row * m + col * n;
        
        bool found_barrier = false;
        for (int i = 0 ; i < sz ; i++) {
            if (obstacleGrid[i * row][i * col])
                found_barrier = true;
            if(found_barrier)
                dp[i * row][i * col] = 0;
            else
                dp[i * row][i * col] = 1;
        }
    }
};