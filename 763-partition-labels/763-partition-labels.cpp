class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int, int>> m;
        init(m, s);
        fill_map(m, s);
        vector<pair<int, int>> intervals = make_intervals(m, s);
        vector<pair<int, int>> merged_intervals = merge(intervals);
        vector<int> sizes;
        for (int i = 0 ; i < merged_intervals.size() ; i++) {
            int st = merged_intervals[i].first;
            int ed = merged_intervals[i].second;
            sizes.push_back(max(1, ed - st + 1));
        }
        return sizes;
    }
    
private:
    vector<pair<int, int>> merge(vector<pair<int, int>> &intervals) {
        int start = intervals[0].first;
        int end = intervals[0].second;
        vector<pair<int, int>> merged;
        for (int i = 1 ; i < intervals.size() ; i++) {
            pair<int, int> interval = intervals[i];
            if (start == end)
                continue;
            if (interval.first > end) {
                merged.push_back({start, end});
                start = interval.first;
                end = interval.second;
            }
            else {
                end = max(end, interval.second);
            }
        }
        merged.push_back({start, end});
        return merged;
    }
    
    vector<pair<int, int>> make_intervals(unordered_map<char, pair<int, int>> &m, string &s) {
        vector<pair<int, int>> intervals;
        for (char c : s) {
            if (m[c].first != -1) {
                intervals.push_back(m[c]);
                m[c] = {-1, -1};
            }
        }
        return intervals;
    }
    
    void fill_map(unordered_map<char,pair<int, int>> &m, string &s) {
        for (int i = 0 ; i < s.length() ; i++) {
            char curr = s[i];
            if (m[curr].first == -1)
                m[curr].first = i;
            else
                m[curr].second = i;
        }
    }
    
    void init(unordered_map<char,pair<int,int>> &m, string &s) {
        for (int i = 0 ; i < s.length() ; i++) {
            char curr = s[i];
            m[curr] = {-1, -1};
        }
    }
};