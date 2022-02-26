class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0, mx = -1e9, mn = 1e9, n = salary.size();
        for (int x : salary) {
            sum += x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        sum = sum - mn - mx;
        return ((sum * 1.0) / ((n - 2) * 1.0));
    }
};