class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        return sol_one(ransomNote, magazine);
        // return sol_two(ransomNote, magazine);
    }
    
private:
    bool sol_two(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        
        int p1 = 0, p2 = 0;
        while (p1 < ransomNote.length() && p2 < magazine.length()) {
            if (ransomNote[p1] < magazine[p2])
                return false;
            if (ransomNote[p1] == magazine[p2]) {
                p1++;
                p2++;
            }
            else {
                p2++;
            }
        }
        return p1 == ransomNote.length();
    }
    
    bool sol_one(string ransomNote, string magazine) {
        vector<int> ransom_freq = get_freq(ransomNote);
        vector<int> mag_freq = get_freq(magazine);
        
        for (int i = 0 ; i < 26 ; i++) {
            if (ransom_freq[i] > mag_freq[i])
                return false;
        }
        
        return true;
    }
    
    vector<int> get_freq(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        return freq;
    }
};