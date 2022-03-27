class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> power(m);
        for (int i = 0 ; i < m ; i++) {
            int cnt = 0;
            for (int j = 0 ; j < n ; j++) {
                if (mat[i][j])
                    cnt++;
            }
            power[i] = {cnt, i};
        }
        
        vector<int> ret;
        sort(power.begin(), power.end());
        for (int i = 0 ; i < k ; i++) {
            ret.push_back(power[i].second);
        }
        return ret;
    }
};