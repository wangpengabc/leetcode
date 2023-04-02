// https://leetcode.cn/problems/reverse-nodes-in-k-group/
// 递归调用


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* a = head;
        ListNode* b = head;
        for (int i=1; i<k && b!=nullptr; i++) {
            b = b->next;
        }
        if (b == nullptr) {
            return head;
        }
        
        ListNode* new_head = reverseKGroup(b->next, k);
        b->next = new_head;
        ListNode* new_head_pre = reverseN(a, k);

        return new_head_pre;
    }

    ListNode* last_next = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            last_next = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = last_next;

        return last;
    }
};
