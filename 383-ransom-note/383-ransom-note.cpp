class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransom_freq = get_freq(ransomNote);
        vector<int> mag_freq = get_freq(magazine);
        
        for (int i = 0 ; i < 26 ; i++) {
            if (ransom_freq[i] > mag_freq[i])
                return false;
        }
        
        return true;
    }
    
private:
    vector<int> get_freq(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        return freq;
    }
};