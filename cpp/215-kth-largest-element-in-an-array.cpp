// https://leetcode.cn/problems/kth-largest-element-in-an-array/
// 二叉树、快排、二叉堆

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for ( const auto& num : nums ) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
