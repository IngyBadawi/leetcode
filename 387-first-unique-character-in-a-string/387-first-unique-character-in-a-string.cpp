class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> m;
        for (int i = 0 ; i < s.length() ; i++) {
            m[s[i]].push_back(i);
        }
        int ind = 1e5;
        for (auto it : m) {
            if (it.second.size() == 1) {
                ind = min(ind, it.second[0]);
            }
        }
        return ind == 1e5? -1 : ind;
    }
};