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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy_low, dummy_high;
        ListNode *head_low, *head_high;
        head_low = &dummy_low;
        head_high = &dummy_high;

        while (head != nullptr) {
            if (head->val < x) {
                head_low->next = head;
                head_low = head;
                head = head->next;
                head_low->next = nullptr; //一定要清理一下next的指向，否则会出现多个节点的next指向同一个node的问题
            } else {
                head_high->next = head;
                head_high = head;
                head = head->next;
                head_high->next = nullptr;
            }
        }
        
        head_low->next = dummy_high.next;
        return dummy_low.next;
    }
};
