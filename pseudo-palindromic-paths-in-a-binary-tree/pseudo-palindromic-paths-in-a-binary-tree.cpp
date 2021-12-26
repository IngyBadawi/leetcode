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
    
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left = 0, right = 0;
        v[root -> val]++;
        if(leaf_node(root)){
            int odd = 0;
            for(int i = 0 ; i < 10 ; i++)
                if(v[i] & 1) odd++;
            
            v[root -> val]--;
            return odd <= 1;
        }
        left = dfs(root -> left);
        right = dfs(root -> right);
        v[root -> val]--;
        return left + right;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        v.resize(10);
        return dfs(root);
    }
private:
    vector<int> v;
    bool leaf_node(TreeNode *root) {
        return (root->left == nullptr && root->right == nullptr);
    }
};