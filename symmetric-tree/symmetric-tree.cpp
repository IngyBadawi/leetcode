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
    bool dfs(TreeNode* p1, TreeNode* p2) {
        if(!p1 && !p2)
            return true;
        if(!p1 || !p2)
            return false;
        if(p1->val != p2->val)
            return false;
        bool left = dfs(p1->left, p2->right);
        bool right = dfs(p1->right, p2->left);
        return left && right;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left, *right = root->right;
        return dfs(left, right);
    }
};