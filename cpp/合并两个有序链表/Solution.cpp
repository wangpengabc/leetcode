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
        ListNode dummy; // 虚拟节点
        ListNode* head; // 关键在于定义一个头指针用于指示
        head = &dummy;
        while (list1!=nullptr && list2!=nullptr) {
            if (list1->val < list2->val) {
                head->next = list1;
                head = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }
        if (list1 != nullptr) {
            head->next = list1;
        }

        if (list2 != nullptr) {
            head->next = list2;
        }

        return dummy.next;
    } 
};
