class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if(s.find(num) != s.end())
                s.erase(s.find(num));
            else
                s.insert(num);
        }
        return *(s.begin());
    }
};