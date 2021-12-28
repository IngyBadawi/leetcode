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
        adjust_lists(head1, head2);
        return add_lists(head1, head2);
    }
    
private:
    void adjust_lists(ListNode* &head1, ListNode* &head2) {
        int length1 = get_length(head1);
        int length2 = get_length(head2);
        if (length2 > length1)
            swap(head1, head2);
        pad_zeros(head2, abs(length1 - length2));
    }
    
    int get_length(ListNode *list) {
        int cnt = 0;
        while (list) {
            cnt++;
            list = list->next;
        }
        return cnt;
    }
    
    void pad_zeros(ListNode *&list, int n) {
        if (!n)
            return;
        ListNode *zeros = new ListNode(0);
        ListNode *temp = zeros;
        while (--n) {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        temp = list;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = zeros;
    }
    
    ListNode *add_lists(ListNode *head1, ListNode *head2) {
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
        if (carry)
            ans->next = new ListNode(1);
        
        return temp->next;
     }
};
