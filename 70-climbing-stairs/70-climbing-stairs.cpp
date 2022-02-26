class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
    
private:
    int solve(int rem, vector<int> &dp) {
        if (rem < 0)
            return 0;
        if (rem == 0)
            return 1;
        if (dp[rem] != -1)
            return dp[rem];
        
        int ans = 0;
        ans += solve(rem - 1, dp);
        ans += solve(rem - 2, dp);
        
        return dp[rem] = ans;
    }
};