// https://leetcode.cn/problems/binary-search/
// 二分查找

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1; // 注意这个位置的 -1

        // if (nums.size() == 1) {
        //     if (nums[0] == target) {
        //         return 0;
        //     } else {
        //         return -1;
        //     }
        // }

        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            }
        }

        return -1;
    }
};
