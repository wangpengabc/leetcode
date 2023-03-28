// https://leetcode.cn/problems/sort-an-array/
// 排序算法汇总

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // if (nums.size() >= 20000) {
        //     return nums;
        // }
        // quick_sort(nums, 0, nums.size()-1);
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }

    void merge_sort(vector<int>& nums, int left, int right) {
        if (left == right) {
            return;
        }

        int middle = (left + right) / 2;

        merge_sort(nums, left, middle);
        merge_sort(nums, middle+1, right);

        // 将排序好的左右分支合并
        vector<int> tmp_nums(right-left+1, 0);
        int tmp_idx = 0;
        int left_idx = left, right_idx = middle+1;
        while(left_idx <= middle && right_idx <= right) {
            if (nums[left_idx] <= nums[right_idx]) {
                tmp_nums[tmp_idx] = nums[left_idx];
                left_idx++;
            } else {
                tmp_nums[tmp_idx] = nums[right_idx];
                right_idx++;
            }
            tmp_idx++;
        }
        while (left_idx <= middle) {
            tmp_nums[tmp_idx] = nums[left_idx];
            left_idx++;
            tmp_idx++;
        }
        while (right_idx <= right) {
            tmp_nums[tmp_idx] = nums[right_idx];
            right_idx++;
            tmp_idx++;
        }
        for (int i=0; i<right-left+1; i++) {
            nums[left+i] = tmp_nums[i];
        }


    }


    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return ;
        }

        // 选择pivot，对数组划分
        int pivot_num = nums[left];
        int pivot_idx = left;
        for (int i=pivot_idx+1; i<=right; i++) {
            if (nums[i] < pivot_num) {
                nums[pivot_idx] = nums[i];
                pivot_idx++;
                nums[i] = nums[pivot_idx];
            }
        }
        nums[pivot_idx] = pivot_num;
        quick_sort(nums, left, pivot_idx-1);
        quick_sort(nums, pivot_idx+1, right);

    }
};
