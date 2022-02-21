class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int threshold = nums.size() >> 1;
        unordered_map <int, int> freq;
        for (auto num : nums) {
            freq[num]++;
            if (freq[num] > threshold)
                return num;
        }
        return 0;
    }
};