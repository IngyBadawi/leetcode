/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* &root) {
        if (!root)
            return root;
        queue <pair<Node*, int>> q;
        q.push({root, 0});
        while (q.size()) {
            Node *curr_node = q.front().first;
            int curr_depth = q.front().second;
            q.pop();
            if (q.size()) {
                if (q.front().second == curr_depth)
                    curr_node->next = q.front().first;
            }
            if (curr_node->left)
                q.push({curr_node->left, curr_depth + 1});
            if (curr_node->right)
                q.push({curr_node->right, curr_depth + 1});
        }
        return root;
    }
};