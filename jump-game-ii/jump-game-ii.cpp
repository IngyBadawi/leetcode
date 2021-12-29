class Solution {
public:
    int jump(vector<int>& nums) {
        return bottom_up_driver(nums);
        // return top_down_driver(nums);
    }
    
private:
    int top_down_driver(vector<int> &nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
    
    int bottom_up_driver(vector<int> &nums) {
        return solve2(nums);
    }
    
    //bottom up
    int solve2(vector<int> &nums) {
        vector<int> dp(nums.size() + 1, 1e9);
        dp[0] = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            for (int j = 1 ; j <= nums[i] ; j++) {
                if (i + j < nums.size() - 1) {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
                else {
                    dp[nums.size() - 1] = min(dp[nums.size() - 1], dp[i] + 1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
    
    //top down
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
