class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map <string, bool> m;
        m = fill_map(wordDict);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1 ; i <= s.length() ; i++) {
            for (int j = i - 1 ; j >= 0 ; j--) {
                if (dp[j]) {
                    string new_word = s.substr(j, i - j);
                    if (m.find(new_word) != m .end())
                        dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
    
private:
    unordered_map <string, bool> fill_map(vector<string> &wordDict) {
        unordered_map <string, bool> m;
        for (string word : wordDict)
            m[word] = true;
        return m;
    }
};