// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// 二分查找
// 关键思想：一定要考虑边缘情况，即开始和结束的位置做特殊处理； 可以自己画一个数组分情况分析一下边缘位置，例如left=0, right=1; left=size-2, right=size-1, 
// 然后对照自己写的左右边界移动判断，分析边缘位置该如何处理

class Solution {
public:
    int left_bound(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        if (nums.size()==0) {
            // if (nums[0] == target) {
            //     return 0;
            // } else {
                return -1;
            // }
        }
        
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }

        if (right < 0 ) {
            if (nums[0] != target) {
                return -1;
            }
        }  

        if (left == nums.size()) {
            if (nums[right] == target) { // 此时right在数组的最后位置
                return right;
            } else {
                return -1;
            }
        }

        return nums[left] == target ? left : -1;
    }

    int right_bound(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        if (nums.size()==0) {
            // if (nums[0] == target) {
            //     return 0;
            // } else {
                return -1;
            // }
        }
        
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }

        if (right < 0 ) {
            if (nums[0] != target) {
                return -1;
            }
        }  

        if (left == nums.size()) {
            if (nums[right] == target) { 
                return right;
            } else {
                return -1;
            }
        }

        return nums[right] == target ? right : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);

        return vector<int>{left, right};
    }
};
