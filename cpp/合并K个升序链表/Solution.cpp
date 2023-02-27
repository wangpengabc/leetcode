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
    struct Status {
        int val;
        ListNode* lnode;
        bool operator<(Status s) const {
            return val > s.val;
        }
    };

    priority_queue<Status> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(-1); 
        ListNode* head = dummy;

        for(ListNode* node : lists) {
            if (node) {
                pq.push({node->val, node});
            }
        }

        while (!pq.empty()) {
            Status min_s = pq.top();
            pq.pop();
            head->next = min_s.lnode;
            head = head->next;
            if (min_s.lnode->next != nullptr) {
                pq.push({min_s.lnode->next->val, min_s.lnode->next});
            }
        }
        return dummy->next;
    }
};
