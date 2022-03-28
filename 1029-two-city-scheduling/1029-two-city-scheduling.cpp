class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> a_cost;
        vector<int> b_cost;
        for (int i = 0 ; i < costs.size() ; i++)
            a_cost.push_back(costs[i][0]), b_cost.push_back(costs[i][1]);
        int n = costs.size() >> 1;
        vector<vector<int>> dp(n * 2 + 1, vector<int> (n + 1, -1));
        return solve(0, 0, 0, a_cost, b_cost, dp, n);
    }
    
private:
    int solve(int ind, int a_taken, int b_taken, vector<int> a_cost, vector<int> b_cost,
             vector<vector<int>> &dp, int n) {
        if (ind == a_cost.size())
            return a_taken == n? 0 : 1e9;
        if (a_taken > n || b_taken > n)
            return 1e9;
        if (dp[ind][a_taken] != -1)
            return dp[ind][a_taken];
        int ans = 1e9;
        
        ans = min(ans, a_cost[ind] + solve(ind + 1, a_taken + 1, b_taken, a_cost, b_cost, dp, n));
        ans = min(ans, b_cost[ind] + solve(ind + 1, a_taken, b_taken + 1, a_cost, b_cost, dp, n));
        
        return dp[ind][a_taken] = ans;
    }
};