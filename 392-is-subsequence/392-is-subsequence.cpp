class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pointer = 0;
        for (int i = 0 ; i < t.length() ; i++) {
            if (t[i] == s[s_pointer])
                s_pointer++;
        }
        return (s_pointer == s.length());
    }
};