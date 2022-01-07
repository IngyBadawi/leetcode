#include <stdlib.h>
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->_head = head;
        set_length(_head);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ind = get_index();
        ListNode *temp = _head;
        for (int i = 0 ; i < ind ; i++)
            temp = temp->next;
        return temp->val;
    }

private:
    ListNode *_head;
    int len;
    
    void set_length(ListNode *list) {
        int cnt = 0;
        while (list) {
            list = list->next;
            cnt++;
        }
        this->len = cnt;
    }
    
    int get_index() {
        int rnd = (rand() % (this->len));
        return rnd;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */