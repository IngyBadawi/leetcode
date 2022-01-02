class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> m;
        int ans = 0;
        for (int i = 0 ; i < time.size() ; i++) {
            int rem = time[i] % 60;
            int twin = (60 - rem) % 60;
            ans += m[twin];
            m[rem]++;
        }
        return ans;
    }
};