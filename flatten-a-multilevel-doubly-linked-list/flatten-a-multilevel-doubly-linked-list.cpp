/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
    
private:
    void solve(Node* &head){
        if (!head)
            return;
        Node *lastOne = nullptr;
        Node *next = head->next;
        if (head->child) {
            lastOne = head->child;
            while(lastOne->next) 
                lastOne = lastOne->next;
            
        
            if (next) {
                next->prev = lastOne;
                lastOne->next = next;
            }
            head->next = head->child;
            head->next->prev = head;
            head->child = nullptr;
        }
        solve(head->next);
    }
};