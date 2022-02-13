class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int tot = (1 << n);
        vector<vector<int>> ret;
        for (int i = 0 ; i < tot ; i++) {
            vector<int> curr = get_permutation(i, nums);
            ret.push_back(curr);
        }
        return ret;
    }
    
private:
    vector<int> get_permutation(int x, vector<int> &nums) {
        vector<int> permutation;
        for (int i = 0 ; i < nums.size() ; i++) {
            int mask = (1 << i);
            if (x & mask)
                permutation.push_back(nums[i]);
        }
        return permutation;
    }
};