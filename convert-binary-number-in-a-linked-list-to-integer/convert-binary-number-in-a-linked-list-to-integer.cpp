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
    int getDecimalValue(ListNode* head) {
        int len = -1;
        ListNode *head_copy = head;
        while(head_copy) {
            len++;
            head_copy = head_copy->next;
        }
        head_copy = head;
        int ans = 0;
        while(head_copy) {
            ans += calc(head_copy->val, len);
            len--;
            head_copy = head_copy->next;
        }
        return ans;
    }
private:
    int calc(int base, int pow) {
        return base * (1 << pow);
    }
};