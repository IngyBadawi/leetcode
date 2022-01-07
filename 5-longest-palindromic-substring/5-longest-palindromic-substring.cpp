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
        while(p1 >= 0 && p2 < s.length()) {
            if(s[p1] != s[p2])
                break;
            res += 2, p1--, p2++;
        }
        return res;
    }
};