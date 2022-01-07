class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max_len = 1, start = 0;
        bool dp[len][len];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0 ; i < len ; i++)
            dp[i][i] = true;
        
        for (int i = 0 ; i < len - 1 ; i++) {
            if (s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
        }
        
        for (int k = 3 ; k <= len ; k++) {
            for (int i = 0 ; i < len - k + 1 ; i++) {
                int st = i, ed = st + k - 1;
                if (dp[st + 1][ed - 1] && s[st] == s[ed]) {
                    dp[st][ed] = true;
                    if (k > max_len)
                        max_len = k, start = i;
                }
            }
        }
        return form_answer(start, max_len, s);
    }
    
private:
    string form_answer (int start, int str_len, string &s) {
        string ret = "";
        for (int i = start ; i <= start + str_len - 1 ; i++)
            ret += s[i];
        return ret;
    }
};