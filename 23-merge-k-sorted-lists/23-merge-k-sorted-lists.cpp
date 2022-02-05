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
        int total_count = append_infinity(lists);
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        int done = 0;
        while (done < total_count) {
            int list_index = get_min_index(lists);
            if (list_index == -1)
                cout<<"oh no"<<endl;
            
            temp->next = new ListNode(lists[list_index]->val);
            temp = temp->next;
            lists[list_index] = lists[list_index]->next;
            done++;
        }
        return ans->next;
    }

private:
    int get_min_index(vector<ListNode*> &lists) {
        int mn = 1e9, min_ind = -1;
        for (int i = 0 ; i < lists.size() ; i++) {
            if (lists[i] && lists[i]->val < mn) {
                min_ind = i;
                mn = lists[i]->val;
            }
        }
        return min_ind;
    }
    
    int append_infinity(vector<ListNode*> &lists) {
        int total_count = 0;
        for (ListNode *list : lists) {
            if (!list) {
                list = new ListNode(1e9);
                continue;
            }
            int list_cnt = 1;
            ListNode *temp = list;
            while(temp->next)
                temp = temp->next, list_cnt++;
            temp->next = new ListNode(1e9);
            total_count += list_cnt;
        }
        return total_count;
    }
};