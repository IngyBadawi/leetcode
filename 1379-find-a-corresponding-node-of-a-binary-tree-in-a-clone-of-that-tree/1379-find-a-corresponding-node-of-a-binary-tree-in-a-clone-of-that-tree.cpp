/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int my_target = target->val;
        TreeNode* ret = nullptr;
        find_node(cloned, my_target, ret);
        return ret;
    }
    
private:
    void find_node(TreeNode* root, int target, TreeNode* &ans) {
        if (!root)
            return;
        if (root->val == target) {
            ans = root;
            return;
        }
        find_node(root->left, target, ans);
        find_node(root->right, target, ans);
    }
};