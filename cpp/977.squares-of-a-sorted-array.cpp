// https://leetcode.cn/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> new_nums(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int n = nums.size() - 1;
        while (left <= right) {
            if (pow(nums[left], 2) > pow(nums[right], 2)) {
                new_nums[n] = pow(nums[left], 2);
                left++;
            } else {
                new_nums[n] = pow(nums[right], 2);
                right--;
            }
            n--;
        }
        return new_nums;

    }
};
