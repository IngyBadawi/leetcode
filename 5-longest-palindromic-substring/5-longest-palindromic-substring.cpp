class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0, st = -1;
        for(int i = 0 ; i < s.length() ; i++) {
            int max_odd = get_max(s, i - 1, i + 1, 1);
            int max_even = get_max(s, i - 1, i, 0);
            int max_palindrome = max(max_odd, max_even);
            if(max_palindrome > mx)
                mx = max_palindrome, st = i - (max_palindrome >> 1);
        }
        return s.substr(st, mx);
    }
    
private:
    int get_max(string &s, int p1, int p2, int res) {
        if(p1 < 0 || p2 >= s.length() || s[p1] != s[p2])
            return res;
        return get_max(s, p1 - 1, p2 + 1, res + 2);
    }
};