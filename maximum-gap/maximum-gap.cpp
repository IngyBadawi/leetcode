class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        map<int, int> m;
        for (int x : nums) {
            m[x]++;
            if (m[x] == nums.size())
                return 0;
        }
        int prev = -1e9;
        int max_gap = -1e9;
        for (auto it : m) {
            if (prev == -1e9)
                prev = it.first;
            else {
                int curr = it.first;
                int curr_gap = abs(curr - prev);
                max_gap = max(curr_gap, max_gap);
                prev = curr;
            }
        }
        return max_gap;
    }
};