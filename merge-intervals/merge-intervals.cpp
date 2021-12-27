class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int my_start = intervals[0][0];
        int my_end = intervals[0][1];
        int i = 0;
        while (i < intervals.size() - 1) {
            int next_start = intervals[i + 1][0];
            int next_end = intervals[i + 1][1];
            if (my_end < next_start) {
                ans.push_back({my_start, my_end});
                my_start = next_start;
                my_end = next_end;
            }
            else {
                my_end = max(my_end, next_end);
            }
            i++;
        }
        ans.push_back({my_start, my_end});
        return ans;
    }
};