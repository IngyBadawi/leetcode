class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq_s = get_freq(s);
        vector<int> freq_t = get_freq(t);
        
        for (int i = 0 ; i < 26 ; i++) {
            if (freq_s[i] != freq_t[i])
                return (i + 'a');
        }
        return 0;
    }
    
private:
    vector<int> get_freq(string s) {
        vector<int> freq(26);
        for (char c : s)
            freq[c - 'a']++;
        return freq;
    }
};