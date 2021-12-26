class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt_even = 0, cnt_odd = 0;
        for (int pos : position) {
            if (pos & 1)
                cnt_odd++;
            else
                cnt_even++;
        }
        return min(cnt_even, cnt_odd);
    }
};