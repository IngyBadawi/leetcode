class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int cnt = 0;
        int p1 = 0, p2 = people.size() - 1;
        while (p1 <= p2) {
            if (people[p1] + people[p2] <= limit) 
                p1++;
            cnt++;
            p2--;
        }
        return cnt;
    }
};