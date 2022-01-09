class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp (n, vector<bool> (n, false));
        set_dp_table(s, dp);
        vector<string> path;
        vector<vector<string>> ans;
        dfs(0, s, path, ans, dp);
        cout<<"cnt = "<<cnt<<endl;
        cout<<"ans size = "<<ans.size()<<endl;
        return ans;
    }
    
private:
    int cnt = 0;
    void dfs(int start_ind, string &s, vector<string> path, vector<vector<string>> &ans,
             vector<vector<bool>> &dp) {
        cnt++;
        if (start_ind == s.length()) {
            ans.push_back(path);
            return;
        }
        vector<bool> curr = dp[start_ind];
        for (int i = start_ind ; i < curr.size() ; i++) {
            if (dp[start_ind][i]) {
                path.push_back(s.substr(start_ind, i - start_ind + 1));
                dfs(i + 1, s, path, ans, dp);
                path.pop_back();
            }
        }
    }
    
    void set_dp_table(string &s, vector<vector<bool>> &dp) {
        int n = s.length();
        for (int i = 0 ; i < n ; i++)
            dp[i][i] = true;
        
        for (int i = 0 ; i < n - 1 ; i++) {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = true;
        }
        
        for (int len = 3 ; len <= n ; len++) {
            for (int i = 0 ; i < n - len + 1 ; i++) {
                int st = i, ed = i + len - 1;
                if (dp[st + 1][ed - 1] && s[st] == s[ed])
                    dp[st][ed] = true;
            }
        }
    }
};