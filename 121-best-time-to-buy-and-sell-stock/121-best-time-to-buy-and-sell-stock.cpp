class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mxs(prices.size());
        int mx_so_far = -1e9, best_profit = -1e9;
        for(int i = prices.size() - 1 ; i >= 0 ; i--) {
            mx_so_far = max(mx_so_far, prices[i]);
            mxs[i] = mx_so_far;
            best_profit = max(best_profit, mxs[i] - prices[i]);
        }
        return max(best_profit, 0);
    }
};