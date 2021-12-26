/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //First solution
    int rangeSumBST1(TreeNode* root, int low, int high) {
        if (!root)
            return 0;
        int curr = 0;
        if (root->val >= low && root->val <= high)
            curr = root->val;
        return curr + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high, -1e9, 1e9);
    }
    
    //Optimized solution
    int solve(TreeNode* root, int low, int high, int left, int right) {
        if (!root)
            return 0;
        if (root->val < left || root->val > right)
            return 0;
        int curr = 0;
        if (root->val >= low && root->val <= high)
            curr = root->val;
        return curr + solve(root->left, low, high, left, root->val - 1) 
                    + solve(root->right, low, high, root->val, right);
    }
};