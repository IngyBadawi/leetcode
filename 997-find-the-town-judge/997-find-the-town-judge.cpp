class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1); // out
        vector<int> trusted(n + 1); // in
        
        for (int  i = 0 ; i < trust.size() ; i++) {
            int a = trust[i][0], b = trust[i][1];
            trusts[a]++;
            trusted[b]++;
        }
        for (int i = 1 ; i <= n ; i++) {
            if (!trusts[i] && trusted[i] == n - 1)
                return i;
        }
        return -1;
    }
};