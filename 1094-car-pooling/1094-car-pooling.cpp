class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector <int> car_load(1005, 0);
        int mx_destination = -1;
        for (int i = 0 ; i < trips.size() ; i++) {
            int passengers = trips[i][0];
            if (passengers > capacity)
                return false;
            int from = trips[i][1];
            int to = trips[i][2];
            mx_destination = max(mx_destination, to);
            car_load[from] += passengers;
            car_load[to] -= passengers;
        }
        
        for (int i = 1 ; i <= mx_destination ; i++) {
            car_load[i] += car_load[i - 1];
            if (car_load[i] > capacity)
                return false;
        }
        return true;
    }
};