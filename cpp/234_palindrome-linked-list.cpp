// https://leetcode.cn/problems/palindrome-linked-list/
// 回文链表
// 递归思路，二叉树前序后序遍历

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
    ListNode* left = nullptr;
    bool res = true;
    bool isPalindrome(ListNode* head) {
        if (left == nullptr) {left = head;}
        if (head == nullptr) return true;
        isPalindrome(head->next);
        if (head->val != left->val) {
            res = false;
        }
        left = left->next;
        return res;
    }
};
