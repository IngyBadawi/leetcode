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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2)
            return nullptr;
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        int n1 = adjust(list1);
        int n2 = adjust(list2);
        return merge(list1, list2, n1, n2);
    }

private:
    int adjust(ListNode* &list) {
        int n = 1;
        ListNode *temp = list;
        while (temp->next) 
            temp = temp->next, n++;
        temp->next = new ListNode(1e9);
        return n;
    }
    
    ListNode *merge(ListNode *list1, ListNode *list2, int n1, int n2) {
        int cnt = 0;
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while (cnt < n1 + n2) {
            if (list1->val <= list2->val) {
                ans->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                ans->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            cnt++;
            ans = ans->next;
        }
        return temp->next;
    }
};