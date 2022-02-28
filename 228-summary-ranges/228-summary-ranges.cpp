class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        if (!n)
            return ret;
        for (int i = 0 ; i < n ; ) {
            int start = i, end = i;
            while (end + 1 < n && nums[end + 1] == nums[end] + 1)
                end++;
            if (end > start)
                ret.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else
                ret.push_back(to_string(nums[start]));
            i = end + 1;
        }
        return ret;
    }
};