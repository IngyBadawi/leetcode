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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        ListNode *l1 = head1, *l2 = head2;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            
            if (sum >= 10)
                sum -= 10, carry = 1;
            else
                carry = 0;
            
            ListNode *curr = new ListNode(sum);
            ans->next = curr;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            if (sum >= 10)
                sum -= 10, carry = 1;
            else
                carry = 0;
            
            ListNode *curr = new ListNode(sum);
            ans->next = curr;
            ans = ans->next;
            l1 = l1->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            if (sum >= 10)
                sum -= 10, carry = 1;
            else
                carry = 0;
            
            ListNode *curr = new ListNode(sum);
            ans->next = curr;
            ans = ans->next;
            l2 = l2->next;
        }
        if (carry)
            ans->next = new ListNode(1);
        return temp->next;
    }
};