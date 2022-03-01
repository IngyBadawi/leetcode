class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -1e9;
        
        for(auto it : nums)
            mx = max(mx, it);
        
        if(mx < 0)
            return mx;
        
        for(int i = 0, sum = 0 ; i < nums.size() ; i++)  {
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            mx = max(mx, sum);
        }
        return mx;
    }
};
