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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        solve(root, balanced);
        return balanced;
    }
    
    int solve(TreeNode *root, bool &balanced) {
        if (!root)
            return 0;
        
        int left = solve(root->left, balanced);
        int right = solve(root->right, balanced);
        bool myself = abs(left - right) <= 1;
        
        balanced &= myself;
         
        return 1 + max(left, right);
    }
};