class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Time complexity: O(nlog(k))
        // Space complexity: O(K)
        set<pair<int, int>> s;
        for (int i = 0 ; i < points.size() ; i++) {
            int x = points[i][0], y = points[i][1];
            int current_distance = fast_pow(x, 2) + fast_pow(y, 2);
            s.insert({current_distance, i});
            if (s.size() > k){
                set<pair<int, int>> :: iterator it = --s.end();
                s.erase(it);
            }
        }
        vector<vector<int>> ans;
        for (auto it : s) {
            ans.push_back(points[it.second]);
        }
        return ans;
    }
    
    vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
        // Time complexity: O(nlog(n))
        // Space complexity: O(n)
        priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for (int i = 0 ; i < points.size() ; i++) {
            int x = points[i][0], y = points[i][1];
            int current_distance = fast_pow(x, 2) + fast_pow(y, 2);
            pq.push({current_distance, i});
        }
        vector<vector<int>> ans;
        for (int i = 0 ; i < k ; i++) {
            int current_index = pq.top().second;
            pq.pop();
            ans.push_back(points[current_index]);
        }
        return ans;
    }
    
private:
    int fast_pow(int base, int exp) {
        if (!exp)
            return 1;
        if (exp & 1)
            return base * fast_pow(base, exp - 1);
        int ans = fast_pow(base, exp>>1);
        return ans * ans;
    }
};