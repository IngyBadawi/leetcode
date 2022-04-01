class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            char h = s[l];
            s[l] = s[r];
            s[r] = h;
            l++, r--;
        }
    }
};