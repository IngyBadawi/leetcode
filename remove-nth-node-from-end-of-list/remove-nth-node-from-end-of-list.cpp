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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = get_length(head);
        int target = len - n;
        if (target == 0)
            return head->next;
        ListNode *temp = head;
        while (--target) {
            temp = temp->next;
        }
        ListNode *next = temp->next->next;
        delete(temp->next);
        temp->next = next;
        return head;
    }
private:
    int get_length(ListNode *head) {
        int cnt = 0;
        while (head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
};