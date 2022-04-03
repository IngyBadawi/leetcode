class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, changes = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                bool left = check(l, r - 1, s);
                bool right = check(l + 1, r , s);
                return (left || right);
            }
            l++, r--;
        }
        return true;
    }
    
private:
    bool check(int l, int r, string s) {
        while (l < r){
            if (s[l] != s[r]) 
                return false;
            
            l++, r--;
        }
        return true;
    }
};