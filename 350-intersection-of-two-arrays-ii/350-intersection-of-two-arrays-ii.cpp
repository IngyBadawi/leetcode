class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1 = get_freq(nums1);
        vector<int> freq2 = get_freq(nums2);
        vector<int> ans = get_intersection(freq1, freq2);
        return ans;
    }
    
private:
    void append(int x, int cnt, vector<int> &ans) {
        while (cnt--)
            ans.push_back(x);
    }
    
    vector<int> get_intersection(vector<int> &freq1, vector<int> &freq2) {
        vector<int> ans;
        for (int i = 0 ; i < 1001 ; i++) {
            int cnt = min(freq1[i], freq2[i]);
            append(i, cnt, ans);
        }
        
        return ans;
    }
    
    vector<int> get_freq(vector<int> &nums) {
        vector<int> freq(1001, 0);
        for (int i = 0 ; i < nums.size() ; i++) 
            freq[nums[i]]++;
        
        return freq;
    }
};