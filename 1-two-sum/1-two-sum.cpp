class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0 ; i < nums.size() ; i++) {
            int twin = target - nums[i];
            if (m.find(twin) != m.end())
                return {m[twin], i};
            m[nums[i]] = i;
        }
        return {};
    }
 
};