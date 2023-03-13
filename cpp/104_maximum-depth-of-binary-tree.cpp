// https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// 二叉树，递归，后序遍历

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);

        return max(left_max_depth, right_max_depth) + 1;
    }
};
