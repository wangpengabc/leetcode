// 将两个链表的首尾相连，如果有相交点总会交汇
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr_A = headA, *ptr_B = headB;

        while (ptr_A != ptr_B) {
            if (ptr_A != nullptr) ptr_A = ptr_A->next;
            else ptr_A = headB;
            if (ptr_B != nullptr) ptr_B = ptr_B->next;
            else ptr_B = headA;
        } 
        return ptr_A;
    }
}; 
