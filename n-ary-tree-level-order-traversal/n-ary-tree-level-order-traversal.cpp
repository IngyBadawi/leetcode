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
        if (!root)
            return {};
        queue<pair<Node*, int>> q;
        vector<vector<int>> ret(1005);
        int height = -1;
        q.push({root, 0});
        while(q.size()) {
            //Extract top
            pair<Node*, int> curr = q.front();
            Node *curr_node = curr.first;
            int curr_depth = curr.second;
            q.pop();
            height = max(height, curr_depth);
            
            //Add it to the vector
            ret[curr_depth].push_back(curr_node->val);
            
            //Insert children
            for (Node *child : curr_node->children) 
                q.push({child, curr_depth + 1});
        }
        ret.resize(height + 1);
        return ret;
    }
};