/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = nullptr;
        if (!head)
            return nullptr;
        ListNode *temp = head;
        while (temp) {
            if(prev == nullptr) {
                prev = temp;
                temp = temp->next;
                continue;
            }
            while (temp && prev->val == temp->val) {
                temp = temp->next;
            }
            prev->next = temp;
            prev = temp;
            if (temp)
                temp = temp->next;
        }
        return head;
    }
};