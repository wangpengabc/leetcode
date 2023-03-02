// 技巧也是双指针+快慢指针;关键在于判断慢指针的移动条件
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast != nullptr) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = fast;
                fast = fast->next;
                slow->next = nullptr;
            } else {
                fast = fast->next;
                slow->next = nullptr;
            }
            
        }
        return head;

    }
};
