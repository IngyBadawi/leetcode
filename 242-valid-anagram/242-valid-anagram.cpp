class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        return solution_one(s, t);
        // return solution_two(s, t);
    }
    
private:
    bool solution_two(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
    
    bool solution_one(string s, string t) {
        vector<int> f1 = get_freq(s);
        vector<int> f2 = get_freq(t);
        return compare(f1, f2);
    }
    
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