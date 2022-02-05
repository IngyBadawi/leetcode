class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, total = 0, curr_total = 0, curr_diff = 0;
        for (int i = 0 ; i < cost.size() ; i++) {
            curr_diff = gas[i] - cost[i];
            total += curr_diff;
            curr_total += curr_diff;
            if (curr_total < 0) {
                start = i + 1;
                curr_total = 0;
            }
        }
        return total < 0? -1 : start;
    }
};