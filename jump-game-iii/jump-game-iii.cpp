class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size() + 1, -1);
        vector<int> vis(arr.size(), 0);
        return solve(start, arr, dp, vis);
    }
    
private:
    int solve (int ind, vector<int> &arr, vector<int> &dp, vector<int> &vis) {
        if (ind >= arr.size() || ind < 0 || vis[ind])
            return 0;
        if (arr[ind] == 0)
            return 1;
        if (dp[ind] != -1)
            return dp[ind];
        int ans = -1e9;
        vis[ind] = 1;
        int plus = solve(ind + arr[ind], arr, dp, vis);
        int minus = solve(ind - arr[ind], arr, dp, vis);
        ans = max(plus, minus);
        return dp[ind] = ans;
    }
};