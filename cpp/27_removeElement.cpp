
// https://leetcode.cn/problems/remove-element/
// 快慢指针技巧

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow_idx=0, fast_idx=0;

        for (int fast_idx=0; fast_idx<nums.size(); fast_idx++) {
            if (nums[fast_idx] != val) {
                nums[slow_idx] = nums[fast_idx];
                slow_idx++;
            } 
        }
        return slow_idx;
    }
};
