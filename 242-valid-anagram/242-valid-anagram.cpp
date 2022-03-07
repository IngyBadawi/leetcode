class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f1 = get_freq(s);
        vector<int> f2 = get_freq(t);
        return compare(f1, f2);
    }
    
private:
    vector<int> get_freq(string s) {
        vector<int> freq(26, 0);
        for (char c : s) 
            freq[c - 'a']++;
        return freq;
    }
    
    bool compare(vector<int> &f1, vector<int> &f2) {
        for (int i = 0 ; i < 26 ; i++) {
            if (f1[i] != f2[i])
                return false;
        }
        return true;
    }
};