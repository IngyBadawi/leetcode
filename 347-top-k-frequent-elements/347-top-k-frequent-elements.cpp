class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) 
            freq[num]++;
        vector<pair<int, int>> ans;
        for (auto it : freq) 
            ans.push_back({it.second, it.first});
        vector<int> ret;
        sort(ans.rbegin(), ans.rend());
        for (int i = 0 ; i < k ; i++)
            ret.push_back(ans[i].second);
        return ret;
    }
};