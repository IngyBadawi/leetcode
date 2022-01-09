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
    vector<int> max_leaves_ancestors(TreeNode *root) {
        set<int> path;
        vector<int> ans;
        dfs(root, path, ans);
        return ans;
    }

private:
    bool isLeaf(TreeNode *node) {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    void dfs(TreeNode *root, set<int> path, vector<int> &max_leaves) {
        if (is_leaf(root)) {
            max_leaves.push_back(*(path.rbegin()));
            return;
        }

        path.insert(root->val);
        if (root->left)
            dfs(root->left, path, max_leaves);
        if (root->right)
            dfs(root->right, path, max_leaves);
        path.erase(root->val);
    }
};