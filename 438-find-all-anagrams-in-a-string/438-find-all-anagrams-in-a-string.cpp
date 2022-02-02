class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_freq = construct_freq(p);
        int p_len = p.length();
        vector<int> start_indices;
        vector<int> curr_freq = construct_freq(s.substr(0, p_len - 1));
       
        for (int i = p_len - 1 ; i < s.length() ; i++) {
            curr_freq[s[i] - 'a']++;
            
            if (are_anagrams(curr_freq, p_freq))
                start_indices.push_back(i - p_len + 1);
            
            curr_freq[s[i - p_len + 1] - 'a']--;
        }
        
        return start_indices;
    }
    
private:
    vector<int> construct_freq(string s) {
        vector<int> freq(26);
        for (int i = 0 ; i < s.length() ; i++) {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    
    bool are_anagrams(vector<int> curr_freq, vector<int> p_freq) {
        for (int i = 0 ; i < 26 ; i++)
            if (curr_freq[i] != p_freq[i])
                return false;
        return true;
    }
};