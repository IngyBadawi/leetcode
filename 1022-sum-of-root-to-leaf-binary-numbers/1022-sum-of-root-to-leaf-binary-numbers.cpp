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
        int ans = 0, path = 0;
        dfs(root, path, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int path, int &ans) {
        if (!root)
            return;
        
        path = path << 1;
        path |= root->val;
        
        if (leaf_node(root)) {
            ans += path;
            return;
        }
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
        path = path >> 1;
    }
    
    bool leaf_node(TreeNode *node) {
        return (node->left == nullptr && node->right == nullptr);
    }
};