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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        
        return bfs(root);
    }
    
private:
    void add_child(int parent_height, TreeNode *child, queue <pair<TreeNode *, int>> &q) {
        if (child == nullptr)
            return;
        q.push({child, parent_height + 1});
    }
    
    vector<int> bfs (TreeNode *root) {
        vector<int> ret;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int prev_height = -1;
        while(q.size()) {
            TreeNode *curr_node = q.front().first;
            int curr_height = q.front().second;
            q.pop();
            
            if (curr_height != prev_height)
                ret.push_back(curr_node->val);
            else
                ret.back() = curr_node->val;
            
            add_child(curr_height, curr_node->left, q);
            add_child(curr_height, curr_node->right, q);
            prev_height = curr_height;
        }
        return ret;
    }
};