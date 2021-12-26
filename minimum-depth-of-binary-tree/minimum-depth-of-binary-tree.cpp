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
private:
    bool isLeaf(TreeNode *node) {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    int solve(TreeNode* root, int depth = 0) {
        if(!root)
            return 1e9;
        if(isLeaf(root))
            return depth;
        return min(solve(root->left, depth + 1), solve(root->right, depth + 1));
    }
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + solve(root);
    }
};