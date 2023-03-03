// 数组操作相关的问题
// 快慢指针技巧

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow_idx=0;

        for (int fast_idx=0; fast_idx<nums.size(); fast_idx++) {
            if (nums[fast_idx] != 0) {
                nums[slow_idx] = nums[fast_idx];
                slow_idx++;
            }
        }

        for (; slow_idx<nums.size(); slow_idx++) {
            nums[slow_idx] = 0;
        }
    }
};
