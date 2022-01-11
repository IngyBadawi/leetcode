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
    int sumRootToLeaf(TreeNode* root) {
        int path = 0;
        return dfs(root, path);
    }
    
private:
    int dfs(TreeNode *root, int path) {
        if (!root)
            return 0;
        
        path = path << 1;
        path |= root->val;
        
        if (leaf_node(root)) {
            return path;
        }
        
        int left = dfs(root->left, path);
        int right = dfs(root->right, path);
        path = path >> 1;
        
        return left + right;
    }
    
    bool leaf_node(TreeNode *node) {
        return (node->left == nullptr && node->right == nullptr);
    }
};