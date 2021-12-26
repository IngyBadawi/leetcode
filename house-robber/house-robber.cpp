class Solution {
public:
    int rob(vector<int>& nums) {
        // return bottom_up(nums);
        vector<vector<int>> dp(nums.size() + 1, vector<int> (2, -1));
        return bottom_up(nums);
        // return top_down(0, false, nums, dp);
    }
private:
    int bottom_up(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        int mx = -1;
        for (int i = 0 ; i < nums.size() ; i++) {
            dp[i] = nums[i];
            mx = max(mx, nums[i]);
        }
        dp[1] = max(dp[0], dp[1]);
        for (int i = 2 ; i < nums.size() ; i++) 
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        
        return dp[nums.size() - 1];
    }
    
    int top_down(int i, bool prev, vector<int> &nums, vector<vector<int>> &dp) {
        if (i == nums.size())
            return 0;
        if (i > nums.size())
            return -1e9;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int ans = -1e9;
        if (!prev)
            ans = max(ans, nums[i] + top_down(i + 1, 1, nums, dp));
        ans = max(ans, top_down(i + 1, 0, nums, dp));
        return dp[i][prev] = ans;
    }
};