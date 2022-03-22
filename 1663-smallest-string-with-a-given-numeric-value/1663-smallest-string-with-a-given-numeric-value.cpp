class Solution {
public:
    string getSmallestString(int n, int k) {
        if (k == n)
            return string (n, 'a');
        
        int a_char = n - 1;
        int rem =  k - a_char;
        if (rem <= 26) {
            char c = rem + 'a' - 1;
            string s = string (a_char, 'a');
            s += c;
            return s;
        }
        int z_end = 0;
        while(rem >= 27) {
            a_char--;
            z_end++;
            rem -= 26;
            rem++;
        }
        char c = rem + 'a' - 1;
        string s = string(a_char, 'a');
        s += c;
        string s_end = string(z_end, 'z');
        s += s_end;
        return s;
    }
};