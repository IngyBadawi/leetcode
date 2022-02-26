class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 2;
        for (int i = 2 ; i < n ; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
        }
        return dp[n - 1];
    }
    
    int climbStairs_topdown(int n) {
        vector<int> dp(n + 1, -1);
        return solve_topdown(n, dp);
    }
    
private:
    int solve_topdown(int rem, vector<int> &dp) {
        if (rem < 0)
            return 0;
        if (rem == 0)
            return 1;
        if (dp[rem] != -1)
            return dp[rem];
        
        int ans = 0;
        ans += solve_topdown(rem - 1, dp);
        ans += solve_topdown(rem - 2, dp);
        
        return dp[rem] = ans;
    }
};