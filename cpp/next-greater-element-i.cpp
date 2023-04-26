// https://leetcode.cn/problems/next-greater-element-i/
// 单调栈，https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-daeca/dan-diao-z-1bebe/
// 每次都将当前可以看到的最大值放入栈中

class Solution {
public:
    unordered_map<int, int> num_to_next_max;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // 构造单调栈
        stack<int> max_stack;
        vector<int> res;
        for (int i=nums2.size()-1; i>=0; i--) {

            // 调整栈
            while (!max_stack.empty() && nums2[i]>max_stack.top()) {
                max_stack.pop();
            }

            num_to_next_max[nums2[i]] = max_stack.empty() ? -1 : max_stack.top();
            max_stack.push(nums2[i]);

        }

        for (auto num1 : nums1) {
            res.push_back(num_to_next_max[num1]);
        }
        return res;

    }
};
