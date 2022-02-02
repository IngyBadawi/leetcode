class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx_so_far = -1e9, best_profit = -1e9;
        for(int i = prices.size() - 1 ; i >= 0 ; i--) {
            mx_so_far = max(mx_so_far, prices[i]);
            best_profit = max(best_profit, mx_so_far - prices[i]);
        }
        return max(best_profit, 0);
    }
};