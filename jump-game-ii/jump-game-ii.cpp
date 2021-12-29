class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
    
private:
    int solve(int ind, vector<int> &nums, vector<int> &dp) {
        if (ind >= nums.size() - 1)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int ans = 1e9;
        for (int i = 1 ; i <= nums[ind] ; i++) {
            ans = min(ans, 1 + solve(ind + i, nums ,dp));
        }
        return dp[ind] = ans;
    }
};