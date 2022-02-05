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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int k = lists.size();
        int total = 0;
        vector<ListNode *> heads;
        for (int i = 0 ; i < k ; i++){
            total += append_infinity(lists[i]);
            heads.push_back(lists[i]);
        }
        
        for (int i = 0 ; i < k ; i++) {
            if (lists[i]->val != 1e5)
                total--;
            pq.push({lists[i]->val, i});
            heads[i] = heads[i]->next;
        }
        
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while (pq.size() && pq.top().first != 1e5) {
            pair<int, int> curr = pq.top();
            int value = curr.first, list_index = curr.second;
            pq.pop();
            if (value != 1e5) {
                temp->next = new ListNode(value);
                temp = temp->next;
                pq.push({heads[list_index]->val, list_index});
                heads[list_index] = heads[list_index]->next;
                total--;
            }
        }
        return ans->next;
    }

private:
    int append_infinity(ListNode *&head) {
        ListNode *temp = head;
        if (!head) {
            head = new ListNode(1e5);
            return 0;
        }
        int cnt = 1;
        while (temp->next) 
            temp = temp->next, cnt++;
        temp->next = new ListNode(1e5);
        return cnt;
    }
};