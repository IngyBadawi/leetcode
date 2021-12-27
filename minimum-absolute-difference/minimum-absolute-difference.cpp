class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int min_diff = 1e9;
        for (int i = 0 ; i < arr.size() - 1 ; i++) 
            min_diff = min(min_diff, abs(arr[i] - arr[i + 1]));
        
        for (int i = 0 ; i < arr.size() - 1 ; i++) {
            if (abs(arr[i] - arr[i + 1]) == min_diff)
                ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};