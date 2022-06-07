class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0)
            return;
        
        adjust(nums1);
        adjust(nums2);
        
        vector<int> ret;
        int p1 = 0, p2 = 0;
        
        while(p1 < m && p2 < n) {
            if (nums1[p1] <= nums2[p2]) 
                ret.push_back(nums1[p1++]);
            
            else
                ret.push_back(nums2[p2++]);
        }
        while (p1 < m)
            ret.push_back(nums1[p1++]);
        while (p2 < n)
            ret.push_back(nums2[p2++]);
        
        nums1 = ret;
        return;
    }
    
private:
    void adjust(vector<int> &nums) {
        nums.push_back(1e9 + 5);
        return;
    }
};