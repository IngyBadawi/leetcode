class Solution {
public:
    long long maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long mx_height = getMaxDiff(h, horizontalCuts);
        long long mx_width = getMaxDiff(w, verticalCuts);
        long long ret = ((mx_height * mx_width) % MOD);
        return ret;
    }
    
private:
    long long MOD = 1e9 + 7;
    
    long long getMaxDiff(int len, vector<int> cuts) {
        sort(cuts.begin(), cuts.end());
        int mx = 0, prev = 0;
        for (int i = 0 ; i < cuts.size() ; i++) {
            int curr = cuts[i] - prev;
            mx = max(mx, curr);
            prev = cuts[i];
        }
        mx = max(mx, len - prev);
        return (mx % MOD);
    }
};