class Solution {
public:
    int maxPower(string s) {
        int pow = 1;
        int curr = 1;
        char prev = s[0];
        for (int i = 1 ; i < s.length() ; i++) {
            if (s[i] == prev)
                curr++;
            else {
                pow = max(pow, curr);
                curr = 1;
                prev = s[i];
            }
        }
        pow = max(pow, curr);
        return pow;
    }
};