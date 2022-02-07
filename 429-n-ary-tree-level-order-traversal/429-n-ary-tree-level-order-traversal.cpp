/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        
        vector<int> level;
        queue<pair<Node* ,int>> q;
        q.push({root, 0});
        int prev_depth = 0;
        
        // BFS
        while(q.size()) {
            //Extract top
            Node *curr_node = q.front().first;
            int curr_depth = q.front().second;
            q.pop();
            
            // Add children
            for (Node *child : curr_node->children) {
                q.push({child, curr_depth + 1});
            }
            
            // Update levels
            if (curr_depth != prev_depth) {
                ret.push_back(level);
                level.clear();
                level.push_back(curr_node->val);
                prev_depth = curr_depth;
                
            }
            
            else {
                level.push_back(curr_node->val);
            }
        }
        ret.push_back(level);
        return ret;
    }
};