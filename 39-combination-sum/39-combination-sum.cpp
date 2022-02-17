class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> path;
        solve(0, target, candidates, ret, path);
        return ret;
    }
    
private:
    void solve(int ind, int rem, vector<int> &candidates, vector<vector<int>> &ret, vector<int> &path) {
        if (rem < 0)
            return;
        
        if (rem == 0) {
            ret.push_back(path);
            return;
        }
        
        for (int i = ind;  i < candidates.size() ; i++) {        
            path.push_back(candidates[i]);
            solve(i, rem - candidates[i], candidates, ret, path);
            path.pop_back();
        }
    }
};