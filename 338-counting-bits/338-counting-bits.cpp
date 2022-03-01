class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for (int i = 0 ; i <= n ; i++) 
            ret.push_back(count_ones(i));
        return ret;
    }
    
private:
    int count_ones(int x) {
        int cnt = 0;
        for (int i = 0 ; i < 31 ; i++) 
            if (x & (1<<i))
                cnt++;
        
        return cnt;
    }
};