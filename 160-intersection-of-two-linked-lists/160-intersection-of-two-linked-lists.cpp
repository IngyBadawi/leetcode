/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, bool> vis;
        while (headA && headB) {
            if (vis[headA])
                return headA;
            if (vis[headB])
                return headB;
            
            if (headA == headB)
                return headA;
            
            vis[headA] = true;
            vis[headB] = true;
            
            headA = headA->next;
            headB = headB->next;
            
            
        }
        while (headA) {
            if (vis[headA])
                return headA;
            vis[headA] = true;
            headA = headA->next;
        }
        while (headB) {
            if (vis[headB])
                return headB;
            vis[headB] = true;
            headB = headB->next;
        }
        return headA == headB? headA : nullptr;
    }
};