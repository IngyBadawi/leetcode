class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int types = 0;
        int prev = -1;
        for (int i = 0 ; i < candyType.size() ; i++) {
            if (candyType[i] != prev)
                types++, prev = candyType[i];
        }
        int to_eat = candyType.size() >> 1;
        if (to_eat >= types)
            return types;
        return to_eat;
    }
};